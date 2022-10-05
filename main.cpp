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

LinkedList<int>list;

    list.push_back(170);
    list.push_back(45);
    list.push_back(75);
    list.push_back(90);
    list.push_back(802);
    list.push_back(24);
    list.push_back(2);
    list.push_back(66);

    list.selection_sort();
    list.print();

}
