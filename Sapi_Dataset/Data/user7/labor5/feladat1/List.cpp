#include <iostream>
#include <list>
#include <vector>
#include "List.h"
#include <stdbool.h>

using namespace std;


List::List() {
	Node* first;
}

List::~List() {
	for (Node* n = this->first; n != nullptr; n = n->next) {
		delete first;
	}
}

bool List::exists(int d) const {
	if (this->nodeCounter != 0 ) {
		for (Node* n = this->first; n != nullptr; n = n->next) {
			if (n->value == d) {
				return true;
			}
		}
		return false;
	}
}

int List::size() const {
	return this->nodeCounter;
}

bool List:: empty()const {
	if (this->nodeCounter == 0) {
		return true;
	}
	return false;
}

void List::insertFirst(int d) {
	Node* n = new Node(d, this->first);
}

void List::remove(int d, DeleteFlag df) {
	Node* current = this->first;
	Node* prev = nullptr;
	while (current != nullptr) {
		bool dLess = df == DeleteFlag::LESS && d < current->value;
		bool dEqual = df == DeleteFlag::EQUAL && d == current->value;
		bool dGreater = df == DeleteFlag::EQUAL && d > current->value;
		if (!this->exists(4)) {
			continue;
		}
		if (dLess || dEqual || dGreater) {
			Node* copy = current;
			current = current->next;
			delete copy;
			if (prev == nullptr) {
				first = current;
			}
			else {
				prev->next = current;
				
			}
			this->nodeCounter--;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

void List::print() const {
	Node* node = this->first;
	while (node != nullptr) {
		cout << node->value;
		node = node->next;
	}
}
