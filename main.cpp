#include <iostream>
#include<string>
#include "LinkedList.h"

int main() {

LinkedList<int>list;

    list.push_back(3);
    list.push_back(1);
    list.push_back(5);
    list.push_back(0);

    list.bubble_sort(&bigger);
    list.print();

}
