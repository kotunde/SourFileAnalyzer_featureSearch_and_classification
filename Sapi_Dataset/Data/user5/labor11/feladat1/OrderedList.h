#pragma once
#include <functional>
#include <iostream>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
private:
	struct Node {
		T value;
		Node * next;
		Node(T value, Node * next) : value(value), next(next) {}
	};
	Node * first;
	int numElements;

public:
	OrderedList() : first(nullptr), numElements(0) {};
	~OrderedList();
	void insert(const T& value);
	void listItems(ostream& os);
	bool isEmpty() const;
	void remove(T& value);
	int size() const;
	bool find(T& value) const;

};template<class T, class LessComp, class Equal>OrderedList<T, LessComp, Equal>::~OrderedList() {	Node * curr;	while (first != nullptr) {		curr = first->next;		delete first;		first = curr;	}}template<class T, class LessComp, class Equal>void OrderedList<T, LessComp, Equal>::insert(const T& value) {	Node * act, * prev;	act = first; prev = nullptr;	while (act != nullptr && LessComp()(act->value, value)) {		prev = act;		act = act->next;	}	if (prev == nullptr) {		first = new Node(value, first);	}	else {		prev->next = new Node(value, act);	}	numElements++;}template<class T, class LessComp, class Equal>void OrderedList<T, LessComp, Equal>::listItems(ostream& os) {	Node * head = first;	while (head != nullptr) {		os << head->value << " ";		head = head->next;	}}template<class T, class LessComp, class Equal>bool OrderedList<T, LessComp, Equal>::isEmpty() const {	return numElements == 0;}template<class T, class LessComp, class Equal>void OrderedList<T, LessComp, Equal>::remove(T& value) {	Node * act = first, *prev = nullptr;	while (act != nullptr && !Equal()(act->value, value)) {		prev = act;		act = act->next;	}	if (prev == nullptr && Equal()(act->value, value) && act != nullptr) {		first = first->next;		delete act;	}	else {		if (Equal()(act->value, value)) {			prev->next = act->next;			delete act;		}	}}