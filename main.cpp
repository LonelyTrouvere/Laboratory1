#include <iostream>
#include<string>
#include "LinkedList.h"

struct Person
{
    int age;
    int job;
};

bool cmp(Person a, Person b)
{
    if (a.age == b.age)
        return a.job<b.job;
    else
        return a.age<b.age;
}

int main() {

LinkedList<float>list;

     list.push_back(0.897);
    list.push_back(0.565);
    list.push_back(0.656);
    list.push_back(0.3234);
    list.push_back(0.665);
    list.push_back(0.3434);

    list.bucket_sort();
    list.print();

}
