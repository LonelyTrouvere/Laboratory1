#include <iostream>

template<typename T>
class ArrayList{
private:
    int MAX_SIZE;
    int Size;
    T *arr;

    void append();

public:
    ArrayList();
    T& operator[](int i);
    void push_back(T data);
    void insert(T data, int pos);
    void pop();
    void erase(int pos);
    int size();
    void clear();
    bool empty();
    void print();
    int Msize(); /// to be deleted

    void bubble_sort(bool (*comparator)(T, T) = &lesser);
    void selection_sort(bool (*comparator)(T, T) = &lesser);
    void insertion_sort(bool (*comparator)(T, T) = &lesser);
};

template<typename T>
T &ArrayList<T>::operator[](int i) {
    return arr[i];
}

template<typename T>
ArrayList<T>::ArrayList() {
    MAX_SIZE = 1;
    Size = 0;
    arr = new T[1];
}

template<typename T>
void ArrayList<T>::push_back(T data) {
    Size++;
    if (Size > MAX_SIZE)
        append();

    arr[Size-1] = data;
}

template<typename T>
void ArrayList<T>::insert(T data, int pos) {
    Size++;
    if (Size>MAX_SIZE)
        append();

    if (pos > Size-1)
        return;

    for (int i = pos; i<Size; i++)
    {
        T temp = arr[i];
        arr[i] = data;
        data = temp;
    }
}

template<typename T>
void ArrayList<T>::pop() {
Size--;
}

template<typename T>
void ArrayList<T>::erase(int pos) {
    if (pos >= Size)
        return;

    Size--;
    for (int i=pos; i<Size; i++)
    {
      arr[i] = arr[i+1];
    }

}

template<typename T>
void ArrayList<T>::append() {
    MAX_SIZE*=2;
    T *newArr = new T[MAX_SIZE];

    memcpy( newArr, arr, (Size-1) * sizeof(int) );

    delete [] arr;
    arr = newArr;
}

template<typename T>
int ArrayList<T>::size() {
    return Size;
}

template<typename T>
void ArrayList<T>::clear() {
    delete []arr;
    arr = new T[MAX_SIZE];
    Size = 0;
}

template<typename T>
bool ArrayList<T>::empty() {
    if (Size)
        return false;
    else
        return true;
}

template<typename T>
int ArrayList<T>::Msize() {
    return MAX_SIZE;
}

template<typename T>
void ArrayList<T>::print() {
    for (int i=0; i<Size; i++)
        std::cout<<arr[i]<<' ';
}

///BUBBLE SORT
template<typename T>
void ArrayList<T>::bubble_sort(bool (*comparator)(T, T)) {

    for (int i = 0; i<Size; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (!comparator(arr[j], arr[j + 1]))
                std::swap(arr[j], arr[j + 1]);
        }
    }

}

template<typename T>
void ArrayList<T>::selection_sort(bool (*comparator)(T, T)) {

    for (int i = 0; i<Size-1; i++)
    {
        T cmpData = arr[i];
        int x = i;
        for (int j = i+1; j<Size; j++)
            if (!comparator(cmpData, arr[j])) {
                cmpData = arr[j];
                x = j;
            }
        std::swap(arr[i], arr[x]);
    }

}

template<typename T>
void ArrayList<T>::insertion_sort(bool (*comparator)(T, T)) {
    for (int i = 1; i < Size; i++)
    {
        int j = i;

        while (j > 0 && comparator(arr[j], arr[j-1]))
        {
            std::swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

