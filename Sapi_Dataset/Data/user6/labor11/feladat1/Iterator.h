#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "OrderedList.h"
#include <iostream>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class Iterator {
private:
	OrderedList<T, LessComp, Equal> & list;
	typename OrderedList<T, LessComp, Equal>::Node* act;

public:
	Iterator(OrderedList<T, LessComp, Equal>&);
	bool hasNext();
	T next();
};

template<class T, class LessComp, class Equal>
inline Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal>& ol):
	list(ol),act(list.first)
{
}

template<class T, class LessComp, class Equal>
inline bool Iterator<T, LessComp, Equal>::hasNext()
{
	if (act->next != nullptr) {
		return true;
	}
	return false;
}

template<class T, class LessComp, class Equal>
inline T Iterator<T, LessComp, Equal>::next()
{
	act = act->next;
	return act->value;
}


#endif /* ITERATOR_H */