#ifndef TEMPLIST_H_INCLUDED
#define TEMPLIST_H_INCLUDED
#include<iostream>
#include<functional>
using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;
        Node(T v, Node* n) : value(v), next(n){}
    };
    Node* first;
    int numElements;

public:
    OrderedList();
    ~OrderedList();
    void insert(T);
    void listItems(ostream& ostr = cout);
    bool isEmpty();
    int size();
    bool find(T);
    void remove(T);


};

//// definiciok ////

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList()
{
    numElements = 0;
    first = nullptr;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList()
{
    numElements = 0;
    while(first!=nullptr)
        {
            Node *act = this->first;
            first = first->next;
            delete act;
        }

    first = nullptr;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T to_be_inserted)
{
    Node* act = first;
    Node* prev = nullptr;
    numElements++;

    while (act != nullptr && LessComp()(act->value, to_be_inserted)){
        prev = act;
        act = act->next;
    }

    if(act == first){
            // ha a feje
        first = new Node(to_be_inserted, first);
        return;
    }

    if(act == nullptr)
        // ha a vegen van
    {
        prev->next = new Node(to_be_inserted, nullptr);

        return;
    }
        //maskepp - kozepe
    prev->next = new Node(to_be_inserted, prev->next);
    return;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream& ostr)
{
    Node* checkpoint = first;
    while(checkpoint != nullptr){
        ostr<<"["<<checkpoint->value<<"] ";
        checkpoint = checkpoint->next;
    }
    ostr<<endl;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty()
{
    if( numElements == 0) {
        return true;
    }
    return false;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size()
{
    return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T what)
{
    Node * act = first;
    while(act!=nullptr) {
        if(act->value==what) {
            return true;
        }
        act= act->next;
    }
    return false;

}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T what)
{
    Node *prev = nullptr ;
    Node *act = first ;

    if(first->value == what){
        first = first->next;
        numElements--;
        return;
    }
    while (act != nullptr)
    {

        if(act->value == what){
            //remove
            prev->next = act->next;
            delete act;
            return;
        }
        prev = act;
        act= act->next;
    }
}


//template<class T, class LessComp, class Equal>
//bool operator==(T p1, T p2)
//{
//    if( p1.fname == p2.fname )
//        if(p1.lname == p2.lname)
//            return true;
//    return false;
//}

#endif // TEMPLIST_H_INCLUDED
