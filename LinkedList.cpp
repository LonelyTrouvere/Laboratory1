//
// Created by 1 on 22.09.2022.
//

#include "LinkedList.h"
#include <iostream>

Node::Node()
{
    this->next = nullptr;
}

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

void LinkedList::merge_sort() {
    head = merge_sort(head);
}

Node *LinkedList::find_mid(Node *headr)
{
        Node *slow = headr;
        Node *fast = headr->next;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }

    return  slow;
}

Node *LinkedList::merger(Node *left, Node *right)
{
    if (!left)
        return right;
    if(!right)
        return left;

    Node *newHead = new Node;
    Node *temp = newHead;

    while(left && right)
    {
        if (left->x == right->x)
        {
            if (left->y < right->y)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
        }
        else
        {
            if (left->x < right->x)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
        }

        temp = temp->next;
    }

    while(left)
    {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }

    while(right)
    {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    return newHead->next;

}

Node *LinkedList::merge_sort(Node *headr) {


       if (!headr || !headr->next)
           return headr;

       Node *left = headr;
       Node *mid = find_mid(headr);
       Node *right = mid->next;

       mid->next = nullptr;

       left = merge_sort(left);
       right = merge_sort(right);

       headr = merger(left, right);
       return headr;
}