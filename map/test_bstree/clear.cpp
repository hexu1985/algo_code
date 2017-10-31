// map::clear
#include <iostream>
#include "bstree_map.h"
#include "bstree_map_iterator.h"
#include "bstree_map_util.h"

int main ()
{
  BSTree_map<char, int> mymap;
  tree_init(&mymap);

  tree_insert_or_assign<char, int>(&mymap, 'x', 100);
  tree_insert_or_assign<char, int>(&mymap, 'y', 200);
  tree_insert_or_assign<char, int>(&mymap, 'z', 300);

  std::cout << "mymap contains:\n";
  for (BSTree_map_iterator<char,int> it=tree_begin(&mymap); it!=tree_end(&mymap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  tree_clear(&mymap);
  tree_insert_or_assign<char, int>(&mymap, 'a', 1101);
  tree_insert_or_assign<char, int>(&mymap, 'b', 2202);

  std::cout << "mymap contains:\n";
  for (BSTree_map_iterator<char,int> it=tree_begin(&mymap); it!=tree_end(&mymap); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
