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

    for (int i = 0; i<10; i++)
    {
        list.push_back(i);
        //std::cout<<list.Msize()<<'\n';
    }

    std::swap(list[1], list[5]);
    list.print();

}
