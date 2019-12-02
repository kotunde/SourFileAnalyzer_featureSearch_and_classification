//
// Created by attila on 03.12.2018.
//
#include <cstdio>
#include <functional>
#include <iostream>

#ifndef TEMPLATES_ORDEREDLIST_H
#define TEMPLATES_ORDEREDLIST_H

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >


class OrderedList {
    struct Node {
        T value; // the node value
        Node *next; // pointer to the next node, nullptr in the last node
        Node(T v, Node *n) : value(v), next(n) {
        }
    };

    Node *first; // pointer to the first node
    int numElements;

public:
    OrderedList();
    ~OrderedList();
    bool isEmpty();
    void insert(const T);
    void listItems(ostream&);
    void remove(const T);
    int size() const;
    bool find(const T) const;
};

template <class T, class LessComp, class Equal >
OrderedList<T, LessComp, Equal>::OrderedList()
{
    first = nullptr;
    numElements = 0;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList()
{
    Node *temp=first;
    while(first!= nullptr)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
    //cout << "\nA dekonstruktor lefutott";
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    return first== nullptr;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T  value)
{
    Node * act=first;
    Node * prev= nullptr;
    while (act!= nullptr && LessComp()(act->value,value))
    {
        prev=act;
        act=act->next;
    }
    if (prev== nullptr)
    {
        first=new Node(value,first);
    }
    else if (act==nullptr)
    {
        prev->next=new Node(value, nullptr);
    }
    else
    {
        prev->next=new Node(value,act);
    }
    ++numElements;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &)
{
    Node * act=first;
    while (act!= nullptr)
    {
        cout << act->value << " ";
        act=act->next;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T value)
{
    Node * act=first;
    Node * prev= nullptr;
    while (act!= nullptr && !(Equal()(act->value,value)))
    {
        prev=act;
        act=act->next;
    }

    if (act!= nullptr && (Equal()(act->value,value)))
    {
        Node* temp=act;
        prev->next=act->next;
        delete temp;
        --numElements;
    }
    else
    {
        cout << " Nincs ilyen elem" << endl;
    }
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const
{
    return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T  value) const
{
    for (Node * temp=first; temp!= nullptr; temp=temp->next)
    {
        if (Equal()(temp->value,value))
        {
            return true;
        }
    }
    return false;
}





#endif //TEMPLATES_ORDEREDLIST_H
