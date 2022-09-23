#include <iostream>
#include "LinkedList.h"

int main() {

LinkedList list;

list.push_back(1,5);
list.push_back(5,1);
list.push_back(3,3);
list.push_back(4, 8);

    merge_sort(list);
}
