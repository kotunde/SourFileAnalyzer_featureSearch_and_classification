#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <functional>
#include <iostream>
using namespace std;

template <class T, class LessComp , class Equal  >
class Iterator;
template <class T, class LessComp = less <T>, class Equal = equal_to <T> >
class OrderedList
{
public:

    friend class Iterator<T,LessComp,Equal>;
    struct Node
    {
        T value;
        Node * next;
        Node(T x, Node * n) : value(x), next(n)
        {
        }
    };
    OrderedList();
    // ~OrderedList();
    bool isEmpty();
    void insert(const T &);
    void remove(T&);
    int size();
    bool find (const T&);
    void listitems (ostream &);


private:

    Node * first;
    int numElements;
};

template <class T, class LessComp, class Equal >
OrderedList<T,LessComp,Equal>::OrderedList()
{
    this->first = nullptr;
    this->numElements = 0;
}


template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::insert (const T & x)
{
    Node * temp = first, *temp2 = nullptr;
    if (first == nullptr)
    {
        first = new Node(x,nullptr);
    }
    else
    {
        Node * uj = new Node(x,nullptr);
        while (temp!=nullptr && LessComp () (temp->value,x))
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (first == temp)
        {
            first = uj;
            uj->next = temp;
        }
        else if (temp == nullptr || LessComp () (temp2->value,x))
        {
            temp2->next=uj;
            uj->next=temp;
        }
    }
    this->numElements++;
    listitems(cout);
}


template <class T, class LessComp, class Equal >
bool OrderedList<T,LessComp,Equal>::isEmpty()
{
    return (this->numElements == 0);
}


template <class T, class LessComp, class Equal >
int OrderedList<T,LessComp,Equal>::size()
{
    return this->numElements;
}

template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::remove(T & x)
{
    Node * temp = first, *temp2 = nullptr;

    if (Equal () (first->value,x))
    {
        temp = first;
        first = first->next;
        delete temp;
        this->numElements--;
        return ;
    }
    if (first->next == nullptr)
    {
        if (first->value == x)
        {
            first = nullptr;
            this->numElements--;
        }
    }
    else
    {

        while (temp!=nullptr && LessComp () (temp->value,x))
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp!=nullptr && Equal () (temp->value,x))
        {
            temp2->next = temp->next;
            delete temp;
            this->numElements--;
        }
    }
}


template <class T, class LessComp, class Equal >
bool OrderedList<T,LessComp,Equal>::find(const T & x)
{
    Node * temp = first;
    while (temp!=nullptr)
    {
        if (Equal () (temp->value,x))
            return true;
        temp = temp ->next;
    }
    return false;
}

template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::listitems(ostream & os)
{
    os<<"\n"<<"list : ";
    Node * temp = first;
    while (temp!=nullptr)
    {
        os<<temp->value<<"; ";
        temp = temp->next;
    }
    os<<"\n";
}


#endif // ORDEREDLIST_H
