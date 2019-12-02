#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

#include <iostream>
#include "OrderedList.h"

using namespace std;

template< class T, class LessComp=less<T>, class Equal=equal_to<T> >

class Iterator{
private:
	OrderedList<T, LessComp, Equal>& list;
	OrderedList<T, LessComp, Equal>::Node* act;
public:
	Iterator(OrderedList<T, LessComp, Equal>&) {};
	bool hasNext();
	T next();
};
template<class T, class LessComp, class Equal>
inline Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal>& l)

	: list(l)
{
	this->act = l.first;
}

template<class T, class LessComp, class Equal>
inline bool Iterator<T, LessComp, Equal>::hasNext()
{
	return this->act != nullptr;
}

template<class T, class LessComp, class Equal>
inline T Iterator<T, LessComp, Equal>::next()
{
	typename OrderedList<T, LessComp, Equal>::Node* curr = this->act;
	this->act = this->act->next;
	return curr->value;
}

#endif // ITERATOR_H_INCLUDED