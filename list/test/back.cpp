#include "dclist.h"
#include "dclist_util.h"
#include <iostream>
 
int main()
{
    DCList<char> letters;
    list_init(&letters, {'o', 'm', 'g', 'w', 't', 'f'});
    if (!list_is_empty(&letters)) {
        std::cout << "The last character is: " << *list_data(list_node<char>(list_tail(&letters))) << '\n';
    }  
    list_destroy(&letters);
}
