#include <iostream>

#include "List.h"

using namespace std;

List::List(){
    this->first=nullptr;
    //cout<<"konstruktor\n";
}

List::~List(){
    //cout<<"destruktor\n";
    if(this->first!=nullptr){
        Node* node=this->first;
        for(int i=0; i<this->nodeCounter; i++){
            this->first=node->next;
            delete(node);
        }
        delete(this->first);
    }
}

bool List::exists(int d) const{
    Node* node=this->first;
    for(int i=0; i<this->nodeCounter; i++){
        if(node->value==d){
            delete(node);
            return true;
        }
        node=node->next;
    }
    delete(node);
    return false;
}

int List::size() const{
    return this->nodeCounter;
}

bool List::empty() const{
    if(this->nodeCounter==0){
        return true;
    }
    return false;
}

void List::insertFirst(int d){
    //Node* node=new Node(d,this->first);
    //this->first=node;
    this->first=new Node(d,this->first);
    this->nodeCounter++;
}

void List::remove(int d, DeleteFlag df){
    if(this->nodeCounter==0){
        exit(1);
    }
    if(this->first->value==d && df==DeleteFlag::LESS){
        exit(1);
    }

    Node* current, *previous;

    if(df==DeleteFlag::LESS){
        current=this->first;
        if((current->next)->value==d){
            this->first=current->next;
            delete current;
            this->nodeCounter--;
        }
        else{
            for(int i=1; i<this->nodeCounter-1; i++){
                previous=current;
                current=current->next;
                if((current->next)->value==d){
                   previous->next=current->next;
                   delete current;
                   this->nodeCounter--;
                }
            }
        }
    }
    if(df==DeleteFlag::EQUAL){
        current=this->first;
        if(current->value==d){
            this->first=current->next;
            delete current;
            this->nodeCounter--;
        }
        else{
            for(int i=1; i<this->nodeCounter; i++){
                previous=current;
                current=current->next;
                if(current->value==d){
                   previous->next=current->next;
                   delete current;
                   this->nodeCounter--;
                }
            }
        }
    }
    if(df==DeleteFlag::GREATER){
        current=this->first;
        for(int i=1; i<this->nodeCounter; i++){
                previous=current;
                current=current->next;
                if(previous->value==d){
                   previous->next=current->next;
                   delete current;
                   this->nodeCounter--;
                }
        }
    }
    delete current, previous;
}

void List::print()const{
    Node* node=this->first;
    for(int i=0; i<this->nodeCounter; i++){
        cout<<node->value<<" ";
        node=node->next;
    }
    cout<<endl;
    delete(node);
}
