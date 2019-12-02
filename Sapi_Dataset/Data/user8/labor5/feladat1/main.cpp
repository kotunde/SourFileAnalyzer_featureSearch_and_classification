#include <iostream>
#include <list>
#include "list.h"

using namespace std;

bool compare( List& l1, list<int>& l2);

int main()
{
    List list1;
    list<int> list2;
    list<int> list3;
    list<int> list4;


    list1.insertFirst(1);
    list1.insertFirst(2);
    list1.insertFirst(3);
    list1.insertFirst(4);
    list1.insertFirst(5);

    list2.push_front(1);
    list2.push_front(2);
    list2.push_front(3);
    list2.push_front(4);
    list2.push_front(5);

    list3.push_front(1);
    list3.push_front(2);
    list3.push_front(3);
    list3.push_front(4);
    list3.push_front(5);

    list4.push_front(1);
    list4.push_front(2);
    list4.push_front(3);
    list4.push_front(4);
    list4.push_front(5);

    cout<<"Elso lista tartalma: "<<endl;
    list1.print();
    cout<<"Masodik lista tartalma: "<<endl;
    list<int>::const_iterator pos;
    for(pos = list2.begin(); pos!= list2.end(); pos++){
        cout<<*pos<<"  ";
    }


    if(compare(list1, list2)){
            cout<<"\nEgyformak.\n";
    }else{
    cout<<"\nNem egyformak.\n";
    }

    cout<<"\n\n\tTorles utan: 1-bol -> 4-et, 2-bol -> 5-ot\n"<<endl;
    list3.pop_front();
    list1.remove(4, List::DeleteFlag::EQUAL);
    cout<<"Elso lista tartalma: "<<endl;
    list1.print();
    cout<<"Masodik lista tartalma: "<<endl;
    list<int>::const_iterator pos2;
    for(pos2 = list3.begin(); pos2!= list3.end(); pos2++){
        cout<<*pos2<<"  ";
    }


    if(compare(list1, list3)){
            cout<<"\nEgyformak\n";
    }else{
    cout<<"\nNem egyformak\n";
    }

    list1.insertFirst(4);
    cout<<"\n\n\tTorles utan: 1-bol -> 5-ot, 2-bol -> 5-ot\n"<<endl;
    list4.pop_front();
    list1.remove(5, List::DeleteFlag::EQUAL);
    cout<<"Elso lista tartalma: "<<endl;
    list1.print();
    cout<<"Masodik lista tartalma: "<<endl;
    list<int>::const_iterator pos3;
    for(pos3 = list4.begin(); pos3!= list4.end(); pos3++){
        cout<<*pos3<<"  ";
    }


    if(compare(list1, list4)){
            cout<<"\nEgyformak\n";
    }else{
    cout<<"\nNem egyformak\n";
    }

    return 0;
}

bool compare( List& l1, list<int>& l2)
{
    if(l1.size() != l2.size()){return false;}

    int k = l2.size();
    for(int i =0; i<k; i++){
        if(!(l1.exists(l2.front()))){
            return false;
        }
        l2.pop_front();
    }
    return true;
}

