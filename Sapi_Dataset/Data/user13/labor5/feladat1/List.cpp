
#include "List.h"
#include <list>
#include <iostream>

using namespace std;

List::List()
{
	this->first = nullptr;
}

List::~List()
{
	Node *ptr = this->first;
	while (ptr != NULL)
	{
		Node *temp;

		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

bool List::exists(int d) const
{
	for (Node *n = this->first; n != nullptr; n = n->next) {
		if (n->value == d) {
			return true;
		}
	}
	return false;
}

int List::size() const
{
	int temp=0;
	for (Node *n = this->first; n != nullptr; n = n->next) {
		temp++;
	}
	return temp;
}

bool List::empty() const
{
	return first==nullptr;
}

void List::insertFirst(int d)
{
	first = new Node(d, first);
	nodeCounter++;
}



void List::remove(int d, DeleteFlag df)
{

	if (df == DeleteFlag::EQUAL) {
		Node* prev = nullptr;
		Node* current = this->first;
		while (current != nullptr) {
			if ( current->value == d ) {
				Node* x = current;
				if (prev != nullptr) {
					prev->next = current->next;
				}
				else {
					this->first = current->next;
				}
				current = current->next;
				delete x;
			}
			else {
				prev = current;
				current = current->next;
			}
			
		}
		
	}
	if (df == DeleteFlag::LESS) {
		Node* prev = nullptr;
		Node* current = this->first;
		while (current != nullptr) {
			if (current->value < d) {
				Node* x = current;
				if (prev != nullptr) {
					prev->next = current->next;
				}
				else {
					this->first = current->next;
				}
				current = current->next;
				delete x;
			}
			else {
				prev = current;
				current = current->next;
			}

		}

	}
	if (df == DeleteFlag::GREATER) {
		Node* prev = nullptr;
		Node* current = this->first;
		while (current != nullptr) {
			if (current->value > d) {
				Node* x = current;
				if (prev != nullptr) {
					prev->next = current->next;
				}
				else {
					this->first = current->next;
				}
				current = current->next;
				delete x;
			}
			else {
				prev = current;
				current = current->next;
			}

		}

	}
	if (df == DeleteFlag::Ficsor) {
		Node* prev = nullptr;
		Node* current = this->first;
		while (current != nullptr) {
			if (current->value != d) {
				Node* x = current;
				if (prev != nullptr) {
					prev->next = current->next;
				}
				else {
					this->first = current->next;
				}
				current = current->next;
				delete x;
			}
			else {
				prev = current;
				current = current->next;
			}

		}

	}
}

void List::print() const
{
	for (Node *n = this->first; n != nullptr; n = n->next) {
		cout << n->value << ", ";
	}
}

void List::comp(list<int>L1) {
	auto it=L1.begin() ;
	if (this->size() == L1.size()) {
		cout << "egyforma meretu";
	}
	else {
		cout << "nem egyforma meretu";
		return;
	}
	cout << endl;
	for (Node *n = this->first; n != nullptr; n = n->next) {
		
		if (n->value != *it) {
			cout << "nem egyforma elemu";
			return;
		}
		it++;
	}
}


