//
// Created by attila on 22.10.2018.
//

#include <iostream>
#include "list.h"
using namespace std;

List::List()
{
    first= nullptr;
}


List::~List()
{
    Node *temp=first;
    while(first!= nullptr)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
    cout << "\nA dekonstruktor lefutott";

}

int List::size() const
{
    Node* temp=first;
    int nr=0;
    while(temp!= nullptr)
    {
        ++nr;
        temp=temp->next;
    }
    return nr;
}

bool List::exists(int d) const
{
    for(Node* temp=first; temp!=nullptr; temp=temp->next)
    {
        if(temp->value==d)
        {
            return true;
        }
    }
    return false;
}

bool List::empty() const
{
    return List::size() == 0;
}

void List::insertFirst(int d)
{
    first=new Node(d,first);


}

void List::remove(int d, List::DeleteFlag df)
{
    Node* temp_prev=nullptr;
    Node* temp=first;
    bool brk=true;
    while(temp!= nullptr && brk)
    {
        if (df == List::DeleteFlag::LESS && temp->value<d)
        {
            if (temp_prev==nullptr)
            {
                Node* t1=temp;
                first=temp->next;
                delete t1;
            }
            else
            {
                Node* t1=temp;
                temp=temp->next;
                delete t1;
                temp_prev->next=temp;
            }
            brk=false;

        }
        if (df == List::DeleteFlag ::EQUAL && temp->value==d)
        {
            if (temp_prev==nullptr)
            {
                Node* t1=temp;
                first=temp->next;
                delete t1;
            }
            else
            {
                Node* t1=temp;
                temp=temp->next;
                delete t1;
                temp_prev->next=temp;
            }
            brk=false;
        }
        if (df == List::DeleteFlag ::GREATER && temp->value>d)
        {
            if (temp_prev== nullptr)
            {
                Node* t1=temp;
                first=temp->next;
                delete t1;
            }
            else
            {
                Node* t1=temp;
                temp=temp->next;
                delete t1;
                temp_prev->next=temp;
            }
            brk=false;
        }

        if (temp!=nullptr)
        {
            temp_prev=temp;
            temp=temp->next;
        }

    }
}

void List::print() const
{
    for(Node *temp=first; temp!= nullptr; temp=temp->next)
    {
        cout<<temp->value << " ";
    }
}

bool comp(List* mylist, list<int> list)
{
    for (auto& it:list)
    {
        if (!mylist->exists(it))
        {
            return false;
        }
    }
    return true;
}