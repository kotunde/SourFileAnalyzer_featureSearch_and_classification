#include "List.h"
#include <iostream>
using namespace std;
List::List()
{
    this->first=nullptr;
}
List::~List()
{
    Node* temp=this->first;
    while(temp!=nullptr)
    {
        temp = first;
        first=first->next;
        delete temp;

    }
    first=nullptr;

}
int List::size() const
{
    return this->nodeCounter;
}
bool List::empty() const
{
    if(this->nodeCounter!=0)
    {
        return false;
    }
    return true;
}
bool List::exists(int d) const
{
    Node* temp=this->first;
    while(temp!=nullptr)
    {
        if(temp->value==d)
        {
            return true;
        }

        temp=temp->next;
    }
    return false;
}
void List::insertFirst(int d)
{  /* if(first==nullptr){
    first=new Node(d,first);}
    else{*/
    Node * newNodePtr=new Node(d,this->first);
    this->first=newNodePtr;
   // }
    ++this->nodeCounter;

}
void List::remove(int d, DeleteFlag df) {
    Node *traverse = first, *prev = NULL;
	if (df == List::DeleteFlag::LESS) {
		if (traverse->value < d) {
			first = traverse->next;
			delete traverse;
			return;
		}
		else {
			while (traverse->next != NULL && traverse->value >= d) {
				prev = traverse;
				traverse = traverse->next;
			}
			prev->next = traverse->next;
			delete traverse;
		}
	}
	else if (df == List::DeleteFlag::EQUAL) {
		if (traverse->value == d) {
			first = traverse->next;
			delete traverse;
			return;
		}
		else {
			while (traverse->next != NULL && traverse->value != d) {
				prev = traverse;
				traverse = traverse->next;
			}
			prev->next = traverse->next;
			delete traverse;
		}
	}
	else{
		if (traverse->value > d) {
			first = traverse->next;
			delete traverse;
			return;
		}
		else {
			while (traverse->next != NULL && traverse->value < d) {
				prev = traverse;
				traverse = traverse->next;
			}
			prev->next = traverse->next;
			delete traverse;
		}
	}
}
void List::print() const
{
    Node * temp=this->first;
    while(temp!=nullptr)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
