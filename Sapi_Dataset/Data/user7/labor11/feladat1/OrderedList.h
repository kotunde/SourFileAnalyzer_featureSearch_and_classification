#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED
#include <iostream>

using namespace std;


template <class T, class LessComp=less<T>, class Equal = equal_to<T>>

class OrderedList{

    struct Node{
        T value;
        Node* next;
        Node(T value,Node* next)
        {
            this->value=value;
            this->next=next;
        }
    };
    Node* first;
    int numElements;

public:
	OrderedList();
	~OrderedList();
	bool isEmpty();
	void insert(const T&);
    void remove(const T&);
    int size() const {return numElements;}
	bool find(const T& a) const;
	void listItems(ostream& out);
};

template <class T, class LessComp, class Equal >
inline OrderedList<T, LessComp, Equal>::OrderedList() {
	first = nullptr;
	numElements = 0;
}
template <class T, class LessComp, class Equal >
OrderedList<T, LessComp, Equal>::~OrderedList() {
	Node* ptr = this->first;
	while (ptr != NULL) {
		Node* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}
template <class T, class LessComp, class Equal >
bool OrderedList<class T,class LessComp,class Equal>:: isEmpty(){
	return !numElements;
}

template <class T, class LessComp, class Equal >
void OrderedList<class T, class LessComp, class Equal>::insert(const T&) {
	Node* prev = nullptr, current = this->first;
	LessComp lesscomp;
	while (current != nullptr) {
		if (!lessComp(current->value, value)) {
			break;
		}
		p = current;
		current = current->next;
	}
	//
	if (prev == nullptr) {
		this->first = new Node(value, current);
		++numElements;
	}
	else {
		prev->next = new Node(value, current);
		++numElements;
	}
}

template <class T, class LessComp, class Equal >
void OrderedList<class T, class LessComp, class Equal>::remove(const T&) {
	Node* prev = nullptr;
	Node* current = this->first;
	Equal eq;
	if (this->first == nullptr) {
		throw out_of_range("NO FOREST");
	}
	while (current != nullptr) {
		if (eq(current->value, value)) {
			Node* x = current;
			if (prev != nullptr) {
				prev->next = current->next;
			}
			else {
				this->first = current->next;
			}
			current = current->next;
			delete x;
			--numElements;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

template <class T, class LessComp, class Equal >
bool OrderedList<class T, class LessComp, class Equal>::find(const T& a) const {
	Node* current = this->first;
	Equal eq;
	if (current == nullptr) {
		throw out_of_range("NO FOREST");
	}
	while (current != nullptr) {
		if (eq(current->value, value)) {
			return true;
		}
	}
	return false;
}

template <class T, class LessComp, class Equal >
void OrderedList<class T, class LessComp, class Equal>::listItems(ostream& out) {
	if (this->first == nullptr) {
		throw out_of_range("NO FOREST");
	}
	for (Node* n = this->first; n != nullptr; n=n->next) {
		out << n->value << ", ";
	}
}

#endif // ORDEREDLIST_H_INCLUDED
