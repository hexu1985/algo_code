// erasing from map
#include <iostream>
#include "rbtree_map.h"
#include "rbtree_map_iterator.h"
#include "rbtree_map_util.h"

int main ()
{
  RBTree_map<char,int> mymap;
  RBTree_map_iterator<char,int> it;
  tree_init(&mymap);

  // insert some values:
  tree_insert_or_assign<char, int>(&mymap, 'a', 10);
  tree_insert_or_assign<char, int>(&mymap, 'b', 20);
  tree_insert_or_assign<char, int>(&mymap, 'c', 30);
  tree_insert_or_assign<char, int>(&mymap, 'd', 40);
  tree_insert_or_assign<char, int>(&mymap, 'e', 50);
  tree_insert_or_assign<char, int>(&mymap, 'f', 60);

  auto x=tree_search(&mymap, 'b');
  tree_delete(&mymap, x);                   // erasing by iterator
  delete x;

  tree_remove(&mymap, 'c');                 // erasing by key

  x=tree_search(&mymap, 'e');
  it = RBTree_map_iterator<char,int>(&mymap, x);
  RBTree_map_iterator<char, int> end = tree_end(&mymap);
  while (it != end) {                       // erasing by range
      x = it.get_node();
      ++it;
      tree_delete(&mymap, x);
      delete x;
  }

  // show content:
  for (auto it = tree_begin(&mymap); it != tree_end(&mymap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
