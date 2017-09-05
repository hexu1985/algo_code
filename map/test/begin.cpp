#include <iostream>
#include "bstree_map.h"
#include "bstree_map_iterator.h"
#include "bstree_map_util.h"
 
int main() {
  BSTree_map<int, float> num_map;
  tree_init(&num_map);
  tree_insert_or_assign<int, float>(&num_map, 4, 4.13);
  tree_insert_or_assign<int, float>(&num_map, 9, 9.24);
  tree_insert_or_assign<int, float>(&num_map, 1, 1.09);
  // calls a_map.begin() and a_map.end()
  for (auto it = tree_begin(&num_map); it != tree_end(&num_map); ++it) {
    std::cout << it->first << ", " << it->second << '\n';
  }
}
