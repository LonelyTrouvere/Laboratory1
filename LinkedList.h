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
    /////////////  MERGE SORT   //////////////////
    Node *merge_sort(Node *headr);
    Node *merger(Node *left, Node *right);
    Node *find_mid(Node *headr);
    ////////////  INSERTION SORT  ///////////////
    Node *insertion_sort(Node *headr);
    ///////////   QUICK SORT    /////////////////
    Node *quick_sort(Node *headr);
    Node *partition(Node *headr);
    Node *swap(Node *headr, Node *first, Node *second);
public:
    LinkedList();
    void push_back(int x, int y);
    void push_front(int x, int y);
    void pop_back();
    void pop_front();
    void swap(int a, int b);
    void clear();
    void printList();
    int size();
    Node *front();
    bool empty();

    void merge_sort();
    void insertion_sort();
    void quick_sort();
};

