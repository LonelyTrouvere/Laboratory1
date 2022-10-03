#include <iostream>
#include<string>
#include "LinkedList.h"

int main() {

LinkedList<std::string>list;

    list.push_front("char");
    list.push_front("mf");
    list.push_front("3");
    list.push_front("bruh");
    list.set("druh", 2);
    list.printList();
    list.clear();

    list.printList();
}
