#include <iostream>
#include "rbtree_map.h"
#include "rbtree_map_util.h"
 
int main()
{  
    RBTree_map<int,char> example;
    tree_init(&example, {{1,'a'},{2,'b'}});
 
    auto search = tree_search(&example, 2);
    if(search != NULL) {
        std::cout << "Found " << tree_data(search)->first << " " << tree_data(search)->second << '\n';
    }
    else {
        std::cout << "Not found\n";
    }
}
