#include "List.h"
#include <iostream>
using namespace std;

List::List(){
    this->first = NULL;
}

List::~List(){
    Node* f = this->first;
    while (f != NULL){
        Node* n = f->next;
        delete f;
        f = n;
    }
    this->first = NULL;
    this->nodeCounter = 0;
}

bool List::exists(int d) const{
    Node* f = this->first;
    while (f != NULL){
        if (f->value == d){return true;}
        f = f->next;
    }
    return false;
}

int List::size() const{
    return this->nodeCounter;
}

bool List::empty() const{
    if (this->nodeCounter == 0){return true;}
    else {return false;}
}

void List::insertFirst(int d){
    Node *n = new Node(d,this->first);
    this->first = n;
    this->nodeCounter++;
}

void List::remove(int d, DeleteFlag df){
    Node* temp = first;
    Node* prev;
    switch (df){
        case DeleteFlag::LESS:
                if (first->value < d){
                    first = first->next;
                    break;
                }
                while (temp != NULL && temp->value >= d){
                        prev = temp;
                        temp = temp->next;
                }
                if (temp != NULL){prev->next = temp->next;}
                break;
        case DeleteFlag::EQUAL:
                if (first->value == d){
                    first = first->next;
                    break;
                }
                while (temp != NULL && temp->value != d){
                    prev = temp;
                    temp = temp->next;
                }
                if (temp != NULL){prev->next = temp->next;}
                break;
        case DeleteFlag::GREATER:
                if (first->value > d){
                    first = first->next;
                    break;
                }
                while (temp != NULL && temp->value != d){
                    prev = temp;
                    temp = temp->next;
                }
                if (temp != NULL){prev->next = temp->next;}
                break;
    }
}

void List::print() const{
    Node* f = this->first;
    while (f != NULL){
        cout << f->value << endl;
        f = f->next;
    }
}
