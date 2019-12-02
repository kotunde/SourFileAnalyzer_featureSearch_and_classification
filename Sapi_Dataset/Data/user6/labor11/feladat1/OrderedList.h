#pragma once
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
private:
	
	struct Node {
		T value;
		Node* next;
		Node(T v, Node* n) : value(v), next(n) {}
	};
	int numElements;
	Node* first;

public:
	OrderedList();
	~OrderedList();
	void insert(const T&);
	void listItems(ostream & os);
	bool isEmpty();
	int size();
	bool find(const T&);
	void remove(const T&);
	template< class T, class LessComp = less<T>, class Equal = equal_to<T> >
	friend class Iterator;
};


template<class T, class LessComp, class Equal>
inline OrderedList<T, LessComp, Equal>::OrderedList()
{
	this->first = nullptr;
	this->numElements = 0;
}

template<class T, class LessComp, class Equal>
inline OrderedList<T, LessComp, Equal>::~OrderedList()
{
	
}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::insert(const T &value)
{
	this->numElements = this->numElements + 1;
	Node *act = first;
	Node *prev = nullptr;
	while (act != nullptr && LessComp()(act->value, value)){
		prev = act;
		act = act->next;
	}
	if (prev == nullptr) {
		first = new Node(value, first);
		return;
	}
	Node * uj = new Node(value, act);
	prev->next = uj;

}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::listItems(ostream & os)
{
	Node *temp = first;
	while (temp != nullptr) {
		os << temp->value << endl;
		temp = temp->next;
	}
	os << endl;
}

template<class T, class LessComp, class Equal>
inline bool OrderedList<T, LessComp, Equal>::isEmpty()
{
	if (numElements != 0) {
		return false;
	}
	return true;
}

template<class T, class LessComp, class Equal>
inline int OrderedList<T, LessComp, Equal>::size()
{
	return numElements;
}

template<class T, class LessComp, class Equal>
inline bool OrderedList<T, LessComp, Equal>::find(const T & what)
{
	Node *temp = first;
	for (int i = 0; i < this->numElements; ++i) {
		if (Equal()(temp->value, what)) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<class T, class LessComp, class Equal>
inline void OrderedList<T, LessComp, Equal>::remove(const T & what)
{
	Node *temp = first;
	Node *temp2 = nullptr;
	if (temp->value == what) {
		first = temp->next;
		delete temp;
	}
	while (temp != nullptr) {
		if (temp->value == what)
		{
			temp2->next = temp2->next->next;
			delete temp;
			break;
		}
		temp2 = temp;
		temp = temp->next;
	}
	
}


#endif /* ORDEREDLIST_H */
