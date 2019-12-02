#include "List.h"
#include <iostream>
#include <stddef.h>

List::List(){
first= nullptr;
}

List::~List(){
for(Node *n=first; n!=nullptr; n=n->next){
    delete(n);
}
}
int List::size() const{
return nodeCounter;
}

bool List::empty() const{
if(nodeCounter==0){
    return true;
}
else{
    return false;
}
}

bool List::exists(int d) const{
for(Node *n=first; n!=nullptr; n=n->next){
    if(n->value==d){
        return true;
    }
}
return false;
}

void List::insertFirst(int d){
this->first=new Node(d,this->first);
++nodeCounter;
}

void List::print() const{
for(Node *n=first; n!=nullptr; n=n->next){
    std::cout << n->value << " ";
}
std::cout << "\n";
}

void List::remove(int d, DeleteFlag df){
Node* prev=nullptr;
Node* curr=this->first;
while(curr!=nullptr){
    if((df==DeleteFlag::EQUAL && curr->value==d)||(df==DeleteFlag::GREATER && curr->value>d)||(df==DeleteFlag::LESS && curr->value<d)){
        Node* x = curr;
        curr=curr->next;
        delete x;
        if(prev==nullptr){
            first=curr;
        }
        else{
            prev->next=curr;
        }
        this->nodeCounter--;
    }
    else{
        prev=curr;
        curr=curr->next;
    }

}
}
