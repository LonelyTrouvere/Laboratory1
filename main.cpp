#include <iostream>
#include<string>
#include "LinkedList.h"
#include "ArrayList.h"

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

ArrayList<int>list;

    list.push_back(64);
    list.push_back(25);
    list.push_back(12);
    list.push_back(22);
    list.push_back(11);

    list.radix_sort();
    list.print();

}
