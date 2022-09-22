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

bool LinkedList::empty() {
    if (head)
        return false;
    else
        return true;
}