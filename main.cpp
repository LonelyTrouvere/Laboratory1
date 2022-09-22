#include <iostream>
#include "LinkedList.h"

int main() {

LinkedList list;

list.push_front(1,5);
list.push_back(3,3);
list.push_front(5,1);
list.clear();

 std::cout<<list.size();

}
