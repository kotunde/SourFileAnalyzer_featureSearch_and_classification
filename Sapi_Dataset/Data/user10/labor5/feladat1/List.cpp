#include "List.h"
#include <iostream>

List::List(){
    std::cout << "Szuletik! :D " << std::endl;
    first = nullptr;
}
List::~List(){
    Node* help_ptr = first;
    while(first){
        first = help_ptr->next;
        delete help_ptr;
        help_ptr = first;
    }
    first = nullptr;
    std::cout << "Elhunyt :'( ";
}
bool List::exists(int d) const{
    Node* help_ptr = first;
    while(help_ptr){
        if(help_ptr->value == d) return true;
        help_ptr = help_ptr->next;
    }
    return false;
}
int List::size() const{return nodeCounter;}
bool List::empty() const{return !nodeCounter;}
void List::insertFirst(int d){
    Node* help_ptr = new Node(d,first);;
    ++nodeCounter;
    first = help_ptr;
}
void List::remove(int d, DeleteFlag df){
    if(!first) return;

    Node* pre = first;
    Node* subj = pre->next;
    if( (DeleteFlag::LESS==df and first->value<d) or
        (DeleteFlag::EQUAL==df and first->value==d) or
        (DeleteFlag::GREATER==df and first->value>d) ){
        subj = first;
        first = first->next;
        delete subj;
        --nodeCounter;
        return;
    }
    while(subj){
        if( (DeleteFlag::LESS==df and subj->value<d) or
            (DeleteFlag::EQUAL==df and subj->value==d) or
            (DeleteFlag::GREATER==df and subj->value>d) ){
            ///subj torlendo node
            pre->next = subj->next;
            delete subj;
            --nodeCounter;
            subj = pre->next;
            return;
        }else{
            subj = subj->next;
            pre = pre->next;
        }
    }

}
void List::print() const{
    Node* help_ptr = first;
    ///std::cout << "List:";
    while(help_ptr){
        std::cout <<help_ptr->value << " ";
        help_ptr = help_ptr->next;
    }
}
