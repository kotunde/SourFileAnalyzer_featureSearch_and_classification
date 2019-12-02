#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED

#include<functional>
#include<iostream>
#include<fstream>

using namespace std;


template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList
{
public:
    OrderedList();
    ~OrderedList();
    bool isEmpty() const;
    void insert(const T&);
    void remove(T&);
    int size() const;
    bool find(const T&) const;
    void listitems(ostream&);
private:
    int numElements{0};
    struct Node
    {
        T value;
        Node* next;
        Node(T v, Node* n) : value(v), next(n)
        {
        }
    };
    Node* first;
};


template<class T, class LessComp, class Equal>
inline OrderedList<T, LessComp, Equal>::OrderedList()
{
    this->first = nullptr;
}

template<class T, class LessComp, class Equal>
inline OrderedList<T, LessComp, Equal>::~OrderedList()
{
    while(first != nullptr)
    {
        Node *aux = first;
        first = first->next;
        delete aux;
    }
    first =nullptr;
}

template<class T, class LessComp, class Equal>
inline bool OrderedList<T, LessComp, Equal>::isEmpty() const
{
    if(numElements == 0)
    {
        return true;
    }
    return false;
}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::insert(const T & d)
{
    Node* prev = nullptr;
    Node* cur = first;
    LessComp comp;
    while(cur != nullptr)
    {

        if(comp(d,cur->value))
        {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    if(prev == nullptr)
    {
        first = new Node(d,first);
        numElements++;
    }

    else
    {
        prev->next = new Node(d,cur);
        numElements++;
    }

}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::remove(T & d)
{
    Node* prev = nullptr;
    Node* cur = first;
    while(cur != nullptr)
    {
        if(cur->value == d)
        {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    if(prev == nullptr)
    {
        first = first->next;
        delete cur;
        numElements--;
    }
    else
    {
        if(cur != nullptr)
        {
            prev->next = cur->next;
            delete cur;
            numElements--;
        }
    }
}

template<class T, class LessComp, class Equal>
inline int OrderedList<T, LessComp, Equal>::size() const
{
    return this->numElements;
}

template<class T, class LessComp, class Equal>
inline bool OrderedList<T, LessComp, Equal>::find(const T & d) const
{
    Node* cur = first;
    Equal equ;
    while(cur != nullptr)
    {
        if(equ(cur->value,d))
        {
            return true;
        }
        cur = cur->next;
    }

    return false;
}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::listitems(ostream &)
{
    Node *aux = first;
    while (aux != nullptr)
    {
        cout << aux->value<< "; ";
        aux = aux->next;

    }
    cout << endl;

}





#endif // ORDEREDLIST_H_INCLUDED
