//
// Created by 1 on 22.09.2022.
//

template <typename T>
class LinkedList {
private:
    class Node{
    public:
        T data;
        Node* next;
        Node(T data, Node* ptr = nullptr){
            this->data = data;
            this->next = ptr;
        }
    };
    Node* head;
    int Size;
    Node *bubble_sort(Node *headr);

public:
    LinkedList();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void set(T data, int i);
    void swap();
    void clear();
    void printList();
    int size();
    bool empty();

    void merge_sort();
    void insertion_sort();
    void quick_sort();
    void bubble_sort();
};

template <typename T>
LinkedList<T>::LinkedList() {
head = nullptr;
Size = 0;
}

template <typename T>
void LinkedList<T>::push_back(T data) {

    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *cur = head;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    Size++;

};

template<typename T>
void LinkedList<T>::printList() {

    if (!head)
        return;

    Node *cur = head;
    while(cur)
    {
        std::cout<<cur->data<<'\n';
        cur = cur->next;
    }
}

template<typename T>
void LinkedList<T>::push_front(T data) {
    Node *newNode = new Node(data);
    if (!head)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    Size++;
}

template<typename T>
void LinkedList<T>::pop_back() {
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

template<typename T>
void LinkedList<T>::pop_front() {
    if (!head)
        return;
    Node *delNode = head;
    head = head->next;
    delete delNode;
    Size--;
}

template<typename T>
void LinkedList<T>::set(T data, int i) {
    if (!head || i > Size)
        return;
    i--;
    Node *cur = head;
    while (i--)
    cur = cur->next;
    cur->data = data;
}

template<typename T>
void LinkedList<T>::clear() {
    while(head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Size = 0;
}

template<typename T>
int LinkedList<T>::size() {
    return Size;
}

template<typename T>
bool LinkedList<T>::empty() {
    if (!Size)
        return true;
    else
        return false;
}

template<typename T>
Node *LinkedList<T>::bubble_sort(LinkedList::Node *headr) {

}

