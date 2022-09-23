//
// Created by 1 on 22.09.2022.
//

#include "LinkedList.h"
#include <iostream>

Node::Node(int x, int y)
{
    this->x = x;
    this->y = y;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
    Size = 0;
}

LinkedList::LinkedList(Node *h, int s) {
    head = h;
    Size = s;
}

void LinkedList::push_back(int x, int y)
{
    Node *newNode = new Node(x, y);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;

        while(current->next)
        {
            current = current->next;
        }
        current->next = newNode;

    }

    Size++;
}

void LinkedList::push_front(int x, int y) {
    Node *newNode = new Node(x,y);

    if (!head)
        newNode->next = nullptr;
    else
        newNode->next = head;

    head = newNode;
    Size++;
}

void LinkedList::pop_back() {
    if (!head)
        return;
    if (Size == 1)
    {
        delete head;
        head = nullptr;
    }
    else {
        Node *prev;
        Node *curr = head;
        while (curr->next) {
             prev = curr;
             curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }
    Size--;
}

void LinkedList::pop_front() {
    if (!head)
        return;
    Node *current = head;
    head = head->next;
    delete current;
    Size--;
}

void LinkedList::printList() {
    if (!head)
    {
        return;
    }

    Node *current = head;
    while(current)
    {
        std::cout<<current->x<<' '<<current->y<<std::endl;
        current = current->next;
    }
   // system("pause");
}

void LinkedList::clear(){
    while(head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Size = 0;
}

int LinkedList::size(){
    return Size;
}

Node * LinkedList::front() {
    return head;
}

bool LinkedList::empty() {
    if (head)
        return false;
    else
        return true;
}

////////////////АЛГОРИТМИ СОРТУВАННЯ

/// merge sort
LinkedList merge(Node *a, Node *b){

    while (a)
    {
        printf("%d %d\n", a->x, a->y);
        a = a->next;
    }
    //b.printList();

    /*Node *ahead = a.front();
    Node *bhead = b.front();
    LinkedList c;

    while (ahead && bhead)
    {
        if (ahead->x == bhead->x)
        {
            if (ahead->y < bhead->y) {
                c.push_back(ahead->x, ahead->y);
                ahead = ahead->next;
            }
            else {
                c.push_back(bhead->x, bhead->y);
                bhead = bhead->next;
            }
        }
        else
        {
            if (ahead->x < bhead->x) {
                c.push_back(ahead->x, ahead->y);
                ahead = ahead->next;
            }
            else {
                c.push_back(bhead->x, bhead->y);
                bhead = bhead->next;
            }
        }
    }

    while (ahead)
    {
        c.push_back(ahead->x, ahead->y);
        ahead = ahead->next;
    }

    while(bhead)
    {
        c.push_back(bhead->x, bhead->y);
        bhead = bhead->next;
    }
    //c.printList();
    return c;*/
}

void merge_sort(LinkedList list) {
    if (list.size() == 0 || list.size() == 1)
        return;

    int mid = list.size()/2 + 1;
    Node *a = list.front();
    Node *temp = list.front();
    Node *b;

    for (int i = 1; i < mid; i++)
    {
        if (i == mid-1) {
            b = temp->next;
            temp->next = nullptr;
        }
        temp = temp->next;
    }

    LinkedList lista = LinkedList(a, list.size()/2);
    LinkedList listb = LinkedList(b, list.size()/2 + list.size()%2);
    /*LinkedList t = LinkedList(a, list.size()/2);
    t.printList();
    printf("\n\n");*/

    /*lista.printList();
    printf("\n");
    listb.printList();
    printf("\n");*/

    merge_sort(lista);
    merge_sort(listb);

    list.clear();
    list = merge(a, b);
}