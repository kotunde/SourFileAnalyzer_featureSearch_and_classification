#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

#include "OrderedList.h"
#include <functional>

template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator{
    friend class OrderedList<T, LessComp, Equal>;
    private:
        OrderedList<T, LessComp, Equal>& list;
        typename OrderedList<T, LessComp, Equal>::Node* act;
    public:
        Iterator(OrderedList<T, LessComp, Equal>&);
        bool hasNext() const;
        T next() const;
};

template <class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal>& lista){
    this->list=lista;
    this->act=lista.first;
}

template <class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() const{
    if(act->next!=nullptr){
        return true;
    }
    return false;
}

template <class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() const{
    T value=this->act->value;
    this->act=this->act->next;
    return value;
}

#endif // ITERATOR_H_INCLUDED
