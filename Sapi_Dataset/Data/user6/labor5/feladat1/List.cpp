#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	this->first=nullptr;
}

List::~List()
{
	while (first != nullptr) {
		Node *temp = first;
		first = first->next;
		delete temp;
	}
}

bool List::exists(int d) const
{
	Node *temp = this -> first;
	while (temp->next != nullptr) {
		if (temp->value == d) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int List::size() const
{
	return this->nodeCounter;
}

bool List::empty() const
{
	if (this->nodeCounter == 0) {
		return true;
	}
	return false;
}

void List::insertFirst(int d)
{
	first = new Node(d,first);
	this->nodeCounter = this->nodeCounter + 1;
}

void List::remove(int d, DeleteFlag df)
{
	Node *temp = first;
	Node *temp2 = temp;

	if (List::DeleteFlag::LESS == df && temp->value < d) {
		first = temp->next;
		delete temp;
		return;
	}
	if (List::DeleteFlag::EQUAL == df && temp->value == d) {
		first = temp->next;
		delete temp;
		return;
	}
	if (List::DeleteFlag::GREATER == df && temp->value > d) {
		first = temp->next;
		delete temp;
		return;
	}
	temp = temp->next;
	while (List::DeleteFlag::LESS == df && temp != nullptr) {
		if (temp->value < d) {
			temp2->next = temp->next;
			delete temp;
			return;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	while (List::DeleteFlag::EQUAL == df && temp != nullptr) {
		if (temp->value == d) {
			temp2->next = temp->next;
			delete temp;
			return;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	while (List::DeleteFlag::GREATER == df && temp != nullptr) {
		if (temp->value > d) {
			temp2->next = temp->next;
			delete temp;
			return;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}

	/*switch (df)
	{
	case List::DeleteFlag::LESS:
		if (temp->value < d) {
			first = temp->next;
			delete temp;
			break;
		}
		while (temp != nullptr) {
			if (temp->next->value < d) {
				temp2->next = temp->next->next;
				delete temp;
				break;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		break;
	case List::DeleteFlag::EQUAL:
		if (temp->value == d) {
			first = temp->next;
			delete temp;
			break;
		}
		while (temp != nullptr) {
			if (temp->next->value == d) {
				temp2->next = temp->next->next;
				delete temp;
				break;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		break;
	case List::DeleteFlag::GREATER:
		if (temp->value > d) {
			first = temp->next;
			delete temp;
			break;
		}
		while (temp != nullptr) {
			if (temp->next->value > d) {
				temp2->next = temp->next->next;
				delete temp;
				break;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
		break;
	default:
		break;
	}*/
}

void List::print() const
{
	Node  *temp = first;
	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
	/*for (Node *temp = first; temp != nullptr; temp = temp->next) {
		cout << temp->value << " ";
	}*/
	cout << endl;
}

