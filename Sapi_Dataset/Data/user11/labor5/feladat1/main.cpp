#include <iostream>
#include "List.h"
#include <list>
using namespace std;
bool compare (const List & ,const list<int> & );
int main()
{   List list1;
    cout<<list1.size()<<endl;
    list1.insertFirst(5);
    cout<<list1.size()<<endl;
    list1.print();
    cout<<endl;
    list1.insertFirst(6);
    list1.insertFirst(3);
    list1.insertFirst(9);
    list1.insertFirst(2);
    list1.insertFirst(10);
    list1.insertFirst(0);
    list1.insertFirst(8);
    list1.insertFirst(3);
    list1.print();
    cout<<endl;
   // cout<<list1.exists(6);
    cout<<"letezik e az 6 elem?"<<endl;
    int l;
    l=list1.exists(6);
    if(l){
        cout<<"letezik az elem"<<endl;
    }
    cout<<"toroli az 5 elemet"<<endl;
    list1.remove(5, List::DeleteFlag::EQUAL);
	list1.print();
	cout<<endl;
	cout<<"toroli az 6 kisebb elemeket"<<endl;
    list1.remove(6, List::DeleteFlag::LESS);
	list1.print();
    cout<<endl;
	cout<<"toroli az 9 nagyobb elemeket"<<endl;
    list1.remove(9, List::DeleteFlag::GREATER);
	list1.print();
	cout <<endl;
	cout <<"be epitettlista feltoltes, muveletek"<<endl;
    list <int> mlist;
    for(int i=0;i<10;++i){
            //eleje szur
        mlist.push_front(i);
    }
    for(auto &i :mlist){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<mlist.size();
    mlist.remove(2);
     for(auto &i :mlist){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<mlist.size();
    cout<<endl;*/
   /* cout<<"Compare fugveny"<<endl;
    List lis;
    int i;
    list<int> lis1;
    for(i=0;i<5;++i){
        lis.insertFirst(i);
        lis1.push_front(i);
    }
    cout<<lis.size();
    cout<<endl;
    cout<<lis1.size();
    cout<<endl;
    lis.print();
    cout<<endl;
     for(auto &i :lis1){
        cout<<i<<" ";
    }
    cout<<endl;

    int k;
    k=compare(lis,lis1);
    if(k){
        cout<<"a beepitett nagyobb"<<endl;
    }
    else {
        cout<<"a beepittet kisebb"<<endl;
    }
    lis.remove(2, List::DeleteFlag::EQUAL);
    lis1.remove(2);
    k=compare(lis,lis1);
    if(k){
        cout<<"a beepitett nagyobb"<<endl;
    }
    else {
        cout<<"a beepittet kisebb"<<endl;
    }
   /* int k;
    k=compare(list1,mlist);
    cout<<k;
    mlist.sort();
      for(auto &i :mlist){
        cout<<i<<" ";}
*/
    return 0;
}
bool compare (const List & l1,const list<int> & l2){
if(l1.size()<l2.size()){
    return true;
}
  return false;
}
