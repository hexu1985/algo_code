// map::insert (C++98)
#include <iostream>
#include "rbtree_map.h"
#include "rbtree_map_iterator.h"
#include "rbtree_map_util.h"

int main ()
{
  RBTree_map<char,int> mymap;
  tree_init(&mymap);

  // first insert function version (single parameter):
  tree_insert_unique(&mymap, 'a', 100);
  tree_insert_unique(&mymap, 'z', 200);

  std::pair<RBTree_map_node<char,int> *, bool> ret;
  ret = tree_insert_unique(&mymap, 'z', 500);
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << *tree_value(ret.first) << '\n';
  }

  // second insert function version (with hint position):
  RBTree_map_iterator<char,int> it;
  tree_insert_unique(&mymap, 'b', 300);     // max efficiency inserting
  tree_insert_unique(&mymap, 'c', 400);     // no max efficiency inserting

  // third insert function version (range insertion):
  RBTree_map<char,int> anothermap;
  tree_init(&anothermap, tree_begin(&mymap), RBTree_map_iterator<char,int>(&mymap, tree_search(&mymap, 'c')));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it = tree_begin(&mymap); it != tree_end(&mymap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it = tree_begin(&anothermap); it != tree_end(&anothermap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
