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

LinkedList<Person>list;

     for (int i=0; i<4; i++)
     {
         int a,b;
         std::cin>>a>>b;
         Person c = {a,b};
         list.push_back(c);
     }

     list.quick_sort(cmp);

    for (int i=1; i<5; i++)
    {
        std::cout<<list[i].age<<list[i].job<<'\n';
    }

}
