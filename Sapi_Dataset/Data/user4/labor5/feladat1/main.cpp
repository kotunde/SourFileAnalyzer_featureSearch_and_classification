#include <iostream>
#include "List.h"
#include <list>

using namespace std;

int main()
{
    List list1;
    list<int> list2;

    cout <<"list1 meret: "<< list1.size()<<endl;
    cout <<"list2 meret: "<< list2.size()<<endl;
    cout <<"ures-e a list1?  "<< list1.empty()<<endl;
    cout <<"ures-e a list2?  "<< list2.empty()<<endl;
    list1.insertFirst(1);
    list2.push_front(1);
    cout <<"list1 meret egy beteves utan: "<< list1.size()<<endl;
    cout <<"list2 meret egy beteves utan: "<< list2.size()<<endl;
    cout <<"ures-e a list1?  "<< list1.empty()<<endl;
    cout <<"ures-e a list2?  "<< list2.empty()<<endl;
    list1.insertFirst(3);
    list2.push_front(3);
    list1.insertFirst(7);
    list2.push_front(7);
    list1.insertFirst(10);
    list2.push_front(10);
    list1.insertFirst(5);
    list2.push_front(5);
    cout <<"list1 meret ot beteves utan: "<< list1.size()<<endl;
    cout <<"list2 meret ot beteves utan: "<< list2.size()<<endl;
    cout <<"list1:"<<endl;
    list1.print();
    cout <<"list2:"<<endl;
    for (auto& v : list2)
    {
        cout << v << " ";
    }
    cout << endl;
    list1.remove(3,List::DeleteFlag::EQUAL);
    list2.remove(3);
    cout <<"list1 meret kivetel utan: "<< list1.size()<<endl;
    cout <<"list2 meret kivetel utan: "<< list2.size()<<endl;
    cout <<"list1:"<<endl;
    list1.print();
    cout <<"list2:"<<endl;
    for (auto& v : list2)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
