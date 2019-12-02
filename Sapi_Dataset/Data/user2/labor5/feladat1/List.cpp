#include "List.h"
#include <iostream>

using namespace std;

List::List() {
	Node* first;
}

List::~List() {
	while (first != nullptr) {
		Node* upcoming = first->next;
		delete first;
		first = upcoming;
	}
}

bool List::exists(int d) const {
	Node* current = first;
	Node* upcoming = current->next;
	while (current->next != nullptr) {
		if (current->value == d) {
			return true;
		}
		current = upcoming;
		upcoming = upcoming->next;
	}
	return false;
}

int List::size() const {
	return this->nodeCounter;
}

bool List::empty() const {
	if (this->nodeCounter == 0 && this->first == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void List::insertFirst(int d) {
	this->first = new Node(d, first);
	this->nodeCounter++;
}

void List::remove(int d, DeleteFlag df) {
	Node* current = this->first;
	Node* prev = nullptr;
	Node* temp = nullptr;
	switch(df) {
	case DeleteFlag::LESS:
		while (current != nullptr) {
			if (current->value < d) {
				if (prev != nullptr) {
					prev->next = current->next;
					--nodeCounter;
					break;
				}
				else {
					first = first->next;
					delete current;
					break;
				}
				prev = current;
				current = current->next;
			}
		}
		break;
	case DeleteFlag::EQUAL:
		while (current->next != nullptr) {
			if (current->value == d) {
				if (prev != nullptr) {
					prev->next = current->next;
					--nodeCounter;
					break;
				}
				else {
					first = first->next;
					delete current;
					break;
				}
				prev = current;
				current = current->next;
			}
		}
		break;
	case DeleteFlag::GREATER:
		while (current != nullptr) {
			if (current->value > d) {
				if (prev != nullptr) {
					prev->next = current->next;
					--nodeCounter;
					break;
				}
				else {
					first = first->next;
					delete current;
					break;
				}
				prev = current;
				current = current->next;
			}
		}
		break;
	}
}

void List::print() const {
	Node* current = first;
	while (current->next != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << current->value << endl;
}