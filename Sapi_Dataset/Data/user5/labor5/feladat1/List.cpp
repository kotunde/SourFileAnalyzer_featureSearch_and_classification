#include "List.h"
#include <iostream>

List::List() {
	this->first = nullptr;
}

List::~List() {
	Node * h;
	while (this->first != nullptr) {
		h = first->next;
		delete first;
		first = h;
	}
	this->nodeCounter = 0;
}

bool List::exists(int d) const {
	Node * h = this->first;
	while (h != nullptr) {
		if (h->value == d) {
			return true;
		}
	}
	return false;
}

int List::size() const {
	return this->nodeCounter;
}

bool List::empty() const {
	if (this->nodeCounter == 0) {
		return true;
	}
	return false;
}

void List::insertFirst(int d) {
	this->first = new Node(d, first);
	this->nodeCounter++;
}

void List::remove(int d, DeleteFlag df) {
	Node * h = first;
	if (df == DeleteFlag::EQUAL) {
		while (!empty() && h->value == d) {
			if (h->next == nullptr) {
				this->first = nullptr;
				h = nullptr;
				this->nodeCounter = 0;
			}
			else {
				h = h->next;
				first = first->next;
				this->nodeCounter--;
			}
		}
		while (h != nullptr && !empty() && h->next != nullptr) {
			if (h->next->value == d) {
				h->next = h->next->next;
				this->nodeCounter--;
			}
			h = h->next;
		}
	}
	else if (df == DeleteFlag::LESS)
	{
		while (!empty() && h->value < d) {
			if (h->next == nullptr) {
				this->first = nullptr;
				h = nullptr;
				this->nodeCounter = 0;
			}
			else {
				h = h->next;
				first = first->next;
				this->nodeCounter--;
			}
		}
		while (h != nullptr && !empty() && h->next != nullptr) {
			if (h->next->value < d) {
				h->next = h->next->next;
				this->nodeCounter--;
			}
			h = h->next;
		}
	}
	else if (df == DeleteFlag::GREATER) {
		while (!empty() && h->value > d) {
			if (h->next == nullptr) {
				this->first = nullptr;
				h = nullptr;
				this->nodeCounter = 0;
			}
			else {
				h = h->next;
				first = first->next;
				this->nodeCounter--;
			}
		}
		while (h != nullptr && !empty() && h->next != nullptr) {
			if (h->next->value > d) {
				h->next = h->next->next;
				this->nodeCounter--;
			}
			h = h->next;
		}
	}
}

void List::print() const {
	Node * h = this->first;
	while (h != nullptr) {
		std::cout << h->value << " ";
		h = h->next;
	}
	std::cout << std::endl;
}

