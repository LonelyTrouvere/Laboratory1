//
// Created by 1 on 22.09.2022.
//
#include <iostream>

template <typename T>
bool bigger (T a, T b)
{
    return a>b;
}
template <typename T>
bool lesser(T a, T b)
{
    return a<b;
}

template <typename T>
class LinkedList {
private:
    class Node{
    public:
        T data;
        Node* next;
        Node()
        {
            this->next = nullptr;
        }
        Node(T data, Node* ptr = nullptr){
            this->data = data;
            this->next = ptr;
        }
    };
    Node* head;
    int Size;

private:
    ///Bubble sort
    Node *bubble_sort(Node *headr, bool (*comparator)(T, T))
    {
        Node *curr = headr;
        Node *end = nullptr;
        int i = 1;

        while (end!=head)
        {
            while(curr->next != end)
            {
                if (!comparator(curr->data, curr->next->data))
                    swap(i, i+1);
                curr = curr->next;
                i++;
            }
            end = curr;
            curr = headr;
            i = 1;
        }
        return headr;
    }

    ///Insertion sort
    Node *insertion_sort(Node *headr, bool (*comparator)(T, T))
    {
        Node *ans = new Node;
        Node *curr = headr;

        while (curr)
        {
            Node *ins = new Node(curr->data);
            Node *temp = ans->next;
            Node *prev_to_temp = nullptr;

            if (!temp)
            {
                ans->next = ins;
            }
            else
            {
                while(temp && comparator(temp->data, ins->data))
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

    ///Merge sort
    Node *find_mid(Node *headr)
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

    Node *merger(Node *left, Node *right, bool (*comparator)(T, T))
    {
        if (!left)
            return right;
        if(!right)
            return left;

        Node *newHead = new Node;
        Node *temp = newHead;

        while(left && right)
        {
            if (comparator(left->data, right->data))
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
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

    Node *merge_sort(Node *headr, bool (*comparator)(T, T)) {


        if (!headr || !headr->next)
            return headr;

        Node *left = headr;
        Node *mid = find_mid(headr);
        Node *right = mid->next;

        mid->next = nullptr;

        left = merge_sort(left, comparator);
        right = merge_sort(right, comparator);

        headr = merger(left, right, comparator);
        return headr;
    }

    ///Quick sort

    Node *partition(Node *headr, bool (*comparator)(T, T)){
        Node *pivot = headr;
        while (pivot->next)
            pivot = pivot->next;

        Node *lesser = headr;
        Node *higher = headr;
        int i = 0, j = 0;

        while(lesser->next)
        {
            if (!comparator(lesser->data, pivot->data))
            {
                lesser = lesser->next;
                i++;
            }
            else
            {
                headr = swap(i, j);

                higher = higher->next;
                lesser = lesser->next;
                i++; j++;
            }
        }

        headr = swap(headr, higher, lesser);
        return headr;
    }

    Node *quick_sort(Node *headr, bool (*comparator)(T, T)) {
        if (!headr || !headr->next)
            return headr;

        Node *pivot = headr;
        while (pivot->next)
            pivot = pivot->next;

        headr = partition(headr, comparator);

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

        left = quick_sort(left, comparator);
        right = quick_sort(right, comparator);

        Node *temp2 = left;
        while(temp2->next)
            temp2 = temp2->next;
        temp2->next = pivot;
        pivot->next = right;

        headr = left;
        return headr;
    }


public:
    LinkedList();
    T& operator[](int i);
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void set(T data, int i);
    void swap(int a, int b);
    void clear();
    void print();
    int size();
    bool empty();

    void merge_sort( bool (*comparator)(T, T) = &lesser);
    void insertion_sort(bool (*comparator)(T, T) = &lesser);
    void quick_sort(bool (*comparator)(T, T) = &lesser);
    void bubble_sort(bool (*comparator)(T, T) = &lesser);
};

template <typename T>
LinkedList<T>::LinkedList() {
head = nullptr;
Size = 0;
}

template <typename T>
T& LinkedList<T>::operator[](int i) {
    int j = 1;
    Node *temp = head;
    while(j<i)
    {
        temp = temp->next;
        j++;
    }
    return temp->data;
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
void LinkedList<T>::print() {

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
void LinkedList<T>::swap(int a, int b) {
    if (!head || !head->next || a == b || a>Size || b>Size)
        return;

    int i = 1, j = 1;
    Node* first = head, *second = head;

    while (i != a) {
        i++;
        first = first->next;
    }
    while(j != b) {
        j++;
        second = second->next;
    }

    T temp = first->data;
    first->data = second->data;
    second->data = temp;
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
void LinkedList<T>::bubble_sort(bool (*comparator)(T, T)) {
    head = bubble_sort(head, comparator);
}

template<typename T>
void LinkedList<T>::insertion_sort(bool (*comparator)(T, T)) {
    head = insertion_sort(head, comparator);
}

template<typename T>
void LinkedList<T>::merge_sort(bool (*comparator)(T, T)) {
    head = merge_sort(head, comparator);
}

template<typename T>
void LinkedList<T>::quick_sort(bool (*comparator)(T, T)) {
    head = merge_sort(head, comparator);
}

