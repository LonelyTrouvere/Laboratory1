//
// Created by 1 on 22.09.2022.
//

class Node{
public:
    int x;
    int y;
    Node* next;
private:
     Node();
     Node(int x, int y);
};

class LinkedList {
private:
    Node* head;
    int size;
};

