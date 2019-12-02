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

};