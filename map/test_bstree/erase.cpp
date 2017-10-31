// erasing from map
#include <iostream>
#include "bstree_map.h"
#include "bstree_map_iterator.h"
#include "bstree_map_util.h"

int main ()
{
  BSTree_map<char,int> mymap;
  BSTree_map_iterator<char,int> it;
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
  it = BSTree_map_iterator<char,int>(x);
  BSTree_map_iterator<char, int> end(NULL);
  while (it != end) {                       // erasing by range
      x = it.node;
      ++it;
      tree_delete(&mymap, x);
      delete x;
  }

  // show content:
  for (auto it = tree_begin(&mymap); it != tree_end(&mymap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
