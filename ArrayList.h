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

template<typename T>
class ArrayList{
private:
    int MAX_SIZE;
    int Size;
    T *arr;

    void append();

    void merge_sort(T arr_s[], int begin, int end, bool (*comparator)(T, T));
    void merger(T arr_s[], int left, int mid, int right, bool (*comparator)(T, T));

    void quick_sort(T arr_s[], int begin, int end, bool (*comparator)(T, T));
    int partition(T arr_s[], int begin, int end, bool (*comparator)(T, T));

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

    void bubble_sort(bool (*comparator)(T, T) = &lesser);
    void selection_sort(bool (*comparator)(T, T) = &lesser);
    void insertion_sort(bool (*comparator)(T, T) = &lesser);
    void merge_sort(bool (*comparator)(T, T) = &lesser);
    void quick_sort(bool (*comparator)(T, T) = &lesser);

    void bucket_sort();
    void radix_sort();
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

    for (int i=0; i<Size-1; i++)
        newArr[i] = arr[i];

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

template<typename T>
void ArrayList<T>::merge_sort(bool (*comparator)(T, T)) {
     merge_sort(arr, 0, Size-1, comparator);
}

template<typename T>
void ArrayList<T>::merger(T arr_s[], int left, int mid, int right, bool (*comparator)(T, T)) {

    int left_s = mid - left + 1, right_s = right - mid;
    T *leftArr = new T[left_s];
    T *rightArr = new T[right_s];

    for (int i=0; i<left_s; i++)
        leftArr[i] = arr_s[left+i];

    for (int i=0; i<right_s; i++)
        rightArr[i] = arr_s[mid+1+i];

    int i=0, j=0, x=left;
    while (i<left_s && j<right_s)
    {
        if (comparator(leftArr[i], rightArr[j]))
        {
            arr_s[x] = leftArr[i];
            i++;
        }
        else
        {
            arr_s[x] = rightArr[j];
            j++;
        }
        x++;
    }

    while (i<left_s)
    {
        arr_s[x] = leftArr[i];
        i++;
        x++;
    }

    while (j<right_s)
    {
        arr_s[x] = rightArr[j];
        j++;
        x++;
    }
    delete []leftArr;
    delete []rightArr;
}

template<typename T>
void ArrayList<T>::merge_sort(T arr_s[], int begin, int end, bool (*comparator)(T, T)) {
    if(begin>=end) return;

    int mid = begin + (end - begin)/2;
    merge_sort(arr_s, begin, mid, comparator);
    merge_sort(arr_s,mid+1, end, comparator);

    merger(arr_s, begin, mid, end, comparator);

}

template<typename T>
void ArrayList<T>::quick_sort(bool (*comparator)(T, T)) {
    quick_sort(arr, 0, Size-1, comparator);
}

template<typename T>
int ArrayList<T>::partition(T *arr_s, int begin, int end, bool (*comparator)(T, T)) {
    int pivot = arr_s[end], i = begin-1;

    for (int j=begin; j<end; j++)
    {
        if (comparator(arr_s[j], pivot))
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[++i], arr[end]);
    return i;
}

template<typename T>
void ArrayList<T>::quick_sort(T *arr_s, int begin, int end, bool (*comparator)(T, T)) {
    if (begin >= end) return;

    int pivot = partition(arr_s, begin, end, comparator);
    quick_sort(arr_s, begin, pivot-1, comparator);
    quick_sort(arr_s, pivot+1, end, comparator);

}

template<typename T>
void ArrayList<T>::bucket_sort() {
        ArrayList<float> bucket[Size];

        for (int i=0; i<Size; i++)
        {
            int x = Size*arr[i];
            bucket[x].push_back(arr[i]);
        }

        for (int i=0; i<Size; i++)
            bucket[i].insertion_sort();

        int x = 0;
        for (int i=0; i<Size; i++)
            for (int j=0; j<bucket[i].size(); j++)
            {
                arr[x] = bucket[i][j];
                x++;
            }

}

template<typename T>
void ArrayList<T>::radix_sort() {

    T ma;

    for (int i=0; i<Size; i++)
        if (arr[i]>ma) ma = arr[i];

    for (int exp = 1; ma/exp>0; exp*=10) {
        ArrayList<T> num[10];

        for (int i = 0; i < Size; i++)
            num[arr[i] / exp % 10].push_back(arr[i]);

        int x = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < num[i].size(); j++)
            {
                arr[x] = num[i][j];
                x++;
            }
    }
}