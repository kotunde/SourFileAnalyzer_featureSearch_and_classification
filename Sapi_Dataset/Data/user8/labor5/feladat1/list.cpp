#include "list.h"

List::List()
{
    first = nullptr;
}

List::~List()
{
    Node* temp = first;
    while(first != nullptr){
        temp = first;
        first = first->next;
        delete temp;
    }
    first = nullptr;
}

bool List::exists(int d) const
{
    Node* temp = this->first;
    while(temp!=nullptr){
        if(temp->value == d){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int List::size() const
{
    return nodeCounter;
}

bool List::empty() const
{
    if(nodeCounter){
        return false;
    }
    return true;
}

void List::insertFirst(int d)
{
    first = new Node(d, first);
    nodeCounter++;
}

void List::remove(int d, DeleteFlag df)
{
    Node* temp = first;
    Node* before = first;
    nodeCounter--;
    switch(df)
    {
        //LESS 1 , EQUAL 2 , GREATER 3
        case List::DeleteFlag::LESS:{
            if(first->value < d){
                first = first->next;
                return;
            }
            while(temp->value >= d){
                before = temp;
                temp = temp->next;
            }
            before->next = temp->next;
            delete temp;
            return;

        }

        case List::DeleteFlag::EQUAL:{
            if(first->value == d){
                first = first->next;
                return;
            }
            while(temp->value != d){
                before = temp;
                temp = temp->next;
            }
            before->next = temp->next;
            delete temp;
            return;
        }

        case List::DeleteFlag::GREATER:{
            if(first->value > d){
                first = first->next;
                return;
            }
            while(temp->value <= d){
                before = temp;
                temp = temp->next;
            }
            before->next = temp->next;
            delete temp;
            return;
        }

    }
}

void List::print() const
{
    Node* temp = first;
    while(temp != nullptr){
        cout<<temp->value<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}
