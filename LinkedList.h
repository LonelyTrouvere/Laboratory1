//
// Created by 1 on 22.09.2022.
//

class Node{
public:
    int x;
    int y;
    Node* next;
    Node();
    Node(int x, int y);
};

class LinkedList {
private:
    Node* head;
    int Size;
public:
    LinkedList();
    LinkedList(Node *h, int s);
    void push_back(int x, int y);
    void push_front(int x, int y);
    void pop_back();
    void pop_front();
    void clear();
    void printList();
    int size();
    Node *front();
    bool empty();
};

LinkedList merge(Node *a, Node *b);
void merge_sort(LinkedList list);