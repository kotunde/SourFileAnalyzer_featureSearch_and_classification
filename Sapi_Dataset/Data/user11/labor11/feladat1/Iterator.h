#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

#include <iostream>
#include <functional>
#include "OrderedList.h"
#include <vector>
using namespace std;

template<class T, class LessComp = less<T>, class Equal = equal_to<T>>
class OrderedList;

template<class T, class LessComp , class Equal >
class Iterator {
	OrderedList<T, LessComp, Equal>& list;
	typename OrderedList<T, LessComp, Equal>::Node *act;
public:
	Iterator(OrderedList<T, LessComp, Equal>&list) :list(list)
	{
		this->act = list.first;
	}
	bool hasNext() const;
	T next() const;

};

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() const {
	if (act->next == nullptr) {
		return true;
	}
	return false;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() const {
	return act->next->value;
}


#endif // ITERATOR_H_INCLUDED
