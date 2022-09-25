#include <iostream>
#include "LinkedList.h"

int main() {

LinkedList list;

list.push_back(1,5);
list.push_back(5,1);
list.push_back(3,3);
list.push_back(4, 8);

   Node *a = new Node;
   a->x = 3;
   a->y = 2;

   Node *b = new Node;
   b->x = 1;
   b->y = 5;

   Node *c = new Node;
   c->x = 3;
   c->y = 1;

   a->next = b;
   b->next = c;

    a = merge_sort(a);

   Node *temp = a;

   while(temp)
   {
       printf("1. %d %d\n", temp->x, temp->y);
       temp = temp->next;
   }

    //merge_sort(list);
    //list.printList();
}
