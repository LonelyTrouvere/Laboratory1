#include <iostream>
#include "LinkedList.h"

int main() {

LinkedList list;

    list.push_back(3,3);
    list.push_back(0,0);
    list.push_back(3,3);
    list.push_back(0,1);
    list.push_back(3, 3);
    list.push_back(3,3);

    list.quick_sort();
    list.printList();
}
