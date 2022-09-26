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

void LinkedList::swap(int a, int b){
    if (a>b)
    {
        int c = a;
        a = b;
        b = c;
    }

    if (a == b)
        return;

    if (b > Size)
        return;
    a--; b--;

    Node *find1 = head, *find2 = head;
    Node *prev1 = nullptr, *prev2 = nullptr;

    while(a--)
    {
        prev1 = find1;
        find1 = find1->next;
    }
    while(b--)
    {
        prev2 = find2;
        find2 = find2->next;
    }

   Node *temp = find1->next;
    prev2->next = find1;
    find1->next = find2->next;

    if (!prev1)
    {
        if (temp == find2)
            find2->next = find1;
        else
        find2->next = temp;
        head = find2;
    }
    else
    {
        if (temp == find2)
            find2->next = find1;
        else
        find2->next = temp;
        prev1->next = find2;
    }
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

/// MERGE SORT

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

/// INSERTION SORT

void LinkedList::insertion_sort() {
    head = insertion_sort(head);
}

Node * LinkedList::insertion_sort(Node *headr)
{
    Node *ans = new Node;
    Node *curr = headr;

    while (curr)
    {
        Node *ins = new Node(curr->x, curr->y);
        Node *temp = ans->next;
        Node *prev_to_temp = nullptr;

        if (!temp)
        {
            ans->next = ins;
        }
        else
        {
            while(temp && temp->x < ins->x)
            {
                prev_to_temp = temp;
                temp = temp->next;
            }

            while(temp && temp->x == ins->x && temp->y < ins->y)
            {
                prev_to_temp = temp;
                temp = temp->next;
            }

            if (prev_to_temp) {
                prev_to_temp->next = ins;
                ins->next = temp;
            }
            else
            {
                ans->next = ins;
                ins->next = temp;
            }
        }
        curr = curr->next;
    }

    return ans->next;

}

/// QUICK SORT

void LinkedList::quick_sort() {
    head = quick_sort(head);
}

Node *LinkedList::swap(Node *headr, Node *first, Node *second)
{
    if (!headr || !headr->next || first == second)
        return headr;

    Node *prev1 = headr;
    Node *prev2 = headr;

    if (first == headr)
        prev1 = nullptr;
    else
    while(prev1->next != first)
        prev1 = prev1->next;
    while(prev2->next != second)
        prev2 = prev2->next;

    Node *temp = first->next;
    prev2->next = first;
    first->next = second->next;

    if (!prev1)
    {
        if (temp == second)
            second->next = first;
        else
            second->next = temp;
        headr = second;
    } else
    {
        if (temp == second)
            second->next = first;
        else
            second->next = temp;
        prev1->next = second;
    }
    Node *t = headr;
    return headr;
}

Node *LinkedList::partition(Node *headr){
    Node *pivot = headr;
    while (pivot->next)
        pivot = pivot->next;

    Node *lesser = headr;
    Node *higher = headr;

    while(lesser->next)
    {
        if (lesser->x == pivot->x)
        {
            if (lesser->y > pivot->y)
            {
                lesser = lesser->next;
            }
            else
            {
                headr = swap(headr, higher, lesser);

                Node *temp = lesser;
                lesser = higher;
                lesser->next = higher->next;
                higher = temp;
                higher->next = temp->next;

                higher = higher->next;
                lesser = lesser->next;
            }
        }

        if (lesser->x > pivot->x)
            {
                lesser = lesser->next;
            }
        else
            {
                headr = swap(headr, higher, lesser);

                Node *temp = lesser;
                lesser = higher;
                lesser->next = higher->next;
                higher = temp;
                higher->next = temp->next;

                higher = higher->next;
                lesser = lesser->next;
            }
        }

    headr = swap(headr, higher, lesser);
    return headr;
}

Node *LinkedList::quick_sort(Node *headr) {
    if (!headr || !headr->next)
        return headr;

    Node *pivot = headr;
    while (pivot->next)
        pivot = pivot->next;

    headr = partition(headr);

    Node *temp = headr;
    while (temp->next != pivot && temp != pivot)
        temp = temp->next;
    if (pivot != temp)
    pivot->next = temp->next->next;
    else {
        pivot->next = temp->next;
    }

    Node *left = headr;
    Node *right = pivot->next;
    temp->next = nullptr;

    left = quick_sort(left);
    right = quick_sort(right);

    Node *temp2 = left;
    while(temp2->next)
        temp2 = temp2->next;
    temp2->next = pivot;
    pivot->next = right;

    headr = left;
    return headr;

}