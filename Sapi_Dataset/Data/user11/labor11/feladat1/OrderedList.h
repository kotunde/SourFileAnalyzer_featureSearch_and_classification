#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED
#include <iostream>
#include <functional>
#include "Iterator.h"

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class Iterator;

template <class T, class LessComp , class Equal >
class OrderedList {
	friend class Iterator<T, LessComp, Equal>;
	struct Node {
		T value;
		Node* next;
		Node(T value, Node* next): value(value), next(next) {}
	};
	Node* first;
	int numElements;
public:
	OrderedList();
	~OrderedList();
	bool isEmpty() const;
	void insert(const T&);
	void remove(const T&);
	int size() const;
	bool find(const T&) const;
	void listItems(ostream&);
};

template<class T, class LessComp, class Equal>
OrderedList<T,LessComp,Equal>::OrderedList() {
	first = nullptr;
	numElements = 0;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
	Node *act = first;
	while (act != nullptr) {
		Node *temp = act;
		act = act->next;
		if (temp != nullptr) {
			delete temp;
		}
	}
	first = nullptr;
	numElements = 0;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() const{
	if (numElements == 0) {
		return true;
	}
	return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T& value) {
	LessComp comp;
	Node *newElement = new Node(value,nullptr);
	Node *act = first, *prev = nullptr;
	while (act != nullptr && comp(act->value, value)) {
		prev = act;
		act = act->next;
	}
	if (prev == nullptr) {
		newElement->next = first;
		first = newElement;
	}
	else {
		prev->next=newElement;
		newElement->next = act;
	}
	numElements++;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T& value) {
	if (find(value)) {			//csak akkor torlunk, ha megtalalhato az elem a listaban
		Node* act = first;
		Equal eq;
		if (eq(first->value, value)) {    //ha az elso elem
			Node* temp = first;
			first = first->next;
			delete temp;
			numElements--;
			return;
		}
		while (act->next!=nullptr) {       //ha koztes elem
			if (eq(act->next->value, value)) {
				Node* temp = act->next;
				act->next = temp->next;
				delete temp;
				numElements--;
				return;
			}
			act = act->next;
		}
		if (eq(act->value, value)) {   //ha pont az utolso elem
			delete act;
			numElements--;
		}
	}
	else {
		return;
	}
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const {
	return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T& value) const {
	if (!isEmpty()) {
		Node* act = first;
		Equal eq;
		while (act != nullptr) {
			if (eq(act->value, value)) {
				return true;
			}
			act = act->next;
		}
	}
	return false;
}

template<class T, class	LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream& os) {
	if (!isEmpty()) {
		Node *act = first;
		while (act != nullptr) {
			cout << act->value << " ";
			act = act->next;
		}
		cout << endl;
	}
	else {
		return;
	}
}


#endif // ORDEREDLIST_H_INCLUDED
