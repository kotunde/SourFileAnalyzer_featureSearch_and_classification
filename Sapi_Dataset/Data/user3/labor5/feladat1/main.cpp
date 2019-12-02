#include <iostream>

#include "List.h"

using namespace std;

int main()
{
    List list1;
    for(int i=12; i>=1; i--){
        list1.insertFirst(i);
    }
    list1.print();

    if(list1.exists(6)){
        cout<<"\nA 6-os benne van\n";
    }
    else{
        cout<<"\nA 6-os nincs benne\n";
    }

    cout<<"\n6-os torlese: ";
    list1.remove(6,List::DeleteFlag::EQUAL);
    list1.print();

    if(list1.exists(6)){
        cout<<"\nA 6-os benne van\n";
    }
    else{
        cout<<"\nA 6-os nincs benne\n";
    }

    cout<<"\n10-es utani torlese: ";
    list1.remove(10,List::DeleteFlag::GREATER);
    list1.print();

    cout<<"\n3-as elotti torlese: ";
    list1.remove(3,List::DeleteFlag::LESS);
    list1.print();

    return 0;
}
