#include "dclist.h"
#include "dclist_util.h"
#include <iostream>
 
int main()
{ 
    DCList<int> nums;
    list_init(&nums, {1, 3, 5, 7});
 
    std::cout << "nums contains " << list_size(&nums) << " elements.\n";

    list_destroy(&nums);
}
