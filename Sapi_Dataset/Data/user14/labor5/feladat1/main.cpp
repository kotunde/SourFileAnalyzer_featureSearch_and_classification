#include <iostream>
#include <list>
#include "list.h"
#include <algorithm>

using namespace std;

int main() {
    List list1;
    cout<< "meret:" << list1.size();
    cout << endl;
    list1.insertFirst(5);
    list1.print();
    cout<< endl;

    list1.insertFirst(4);
    list1.insertFirst(3);
    list1.insertFirst(2);
    list1.print(); cout << endl;
    list1.insertFirst(1);
    list1.print();
    cout<< endl;
    cout << list1.size() << endl ;
    cout<< (list1.exists(4)==1?"Exists 4\n":"Doesn't exist 4\n");
    cout<< (list1.exists(10)==1?"Exists 10\n":"Doesn't exist 10\n");
    cout << endl;
    int n=3;
    cout << "Torli az elso " <<n <<"-nal kisebb elemet: "; list1.remove(3,List::DeleteFlag::LESS);
    list1.print();
    cout<< endl;
    cout << "Torli az elso " <<n <<" elemet: "; list1.remove(3,List::DeleteFlag::EQUAL);
    list1.print();
    cout << endl;
    cout << "Torli az elso " << n <<"-nal nagyobb elemet: "; list1.remove(3,List::DeleteFlag::GREATER);
    list1.print();
    cout << endl;


    /// A dekonstruktor automatikusan lefut? Nem kell delete sem?
    //list1.~List();


    cout << endl << endl;

    ///2-es feladat
    List* mylist2 = new List;
    list <int> list2;

    ///listak feltoltese
    int nr=0;
    for (int i=1; i<10; ++i)
    {
        list2.push_back(i);
    }
//    for (auto& it:list2)
//    {
//        cout<< it << " ";
//    }
    for (nr=9; nr>0;--nr)
    {
        mylist2->insertFirst(nr);
    }
    cout << endl;

    cout << (comp(mylist2,list2)==1?"Egyforma":"Nem egyforma")<<endl;

    ///listamuveletek:
    cout << "Letezik a 4-es?" << endl;
    cout << mylist2->exists(4)<<endl;
    if (std::find(begin(list2),end(list2),4) != end(list2))
    {
        cout << 1;
    } else cout << 0;

    cout << endl << "Meret: "<< endl;
    cout << mylist2->size()<<endl;
    cout << list2.size() << endl;

    mylist2->insertFirst(0);
    list2.push_front(0);

    mylist2->remove(9,List::DeleteFlag::EQUAL);
    list2.remove(9); //van fv a remove_if-en kivul, ami feltetellel torol, hasonloan a sajat fv-hez?

    cout << "A ket lista tartalma: " << endl;
    mylist2->print();
    cout << endl;
    for (auto& it: list2)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << (comp(mylist2,list2)==1?"Egyforma":"Nem egyforma")<<endl;

    return 0;
}