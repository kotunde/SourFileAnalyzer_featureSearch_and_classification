#include "List.h"
#include <iostream>

using namespace std;

List :: List ()
{
    this->first=nullptr;
}

bool List :: exists (int d) const
{
    Node * temp = this->first;
    while (temp!=nullptr)
    {
        if (temp->value == d)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int List :: size() const
{
    return this->nodeCounter;
}


bool List :: empty() const
{
    return (this->nodeCounter == 0);
}

void List :: insertFirst(int d)
{
    Node * temp = new Node(d,this->first);
    this->first = temp;
    this->nodeCounter++;
}

void List :: remove(int d, DeleteFlag df)
{
    Node * temp = this->first;
    Node * prev;
    if (this->nodeCounter)
    {
        if (df == List::DeleteFlag::LESS)
        {
            while (temp!=nullptr)
            {
                if (temp->value<d)
                {
                    if (this->nodeCounter == 1)
                    {
                        this->first = nullptr;
                        this->nodeCounter--;
                        break;
                    }
                    if (temp == first)
                    {
                        first = temp->next;
                        this->nodeCounter--;
                        break;
                    }
                    prev->next = temp->next;
                    delete temp;
                    this->nodeCounter--;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        else if (df == List::DeleteFlag::EQUAL)
        {
            while (temp!=nullptr)
            {
                if (temp->value==d)
                {
                    if (this->nodeCounter == 1)
                    {
                        this->first = nullptr;
                        this->nodeCounter--;
                        break;
                    }
                    if (temp == first)
                    {
                        first = temp->next;
                        this->nodeCounter--;
                        break;
                    }
                    prev->next = temp->next;
                    delete temp;
                    this->nodeCounter--;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }

        }
        else
        {
            while (temp!=nullptr)
            {
                if (temp->value>d)
                {
                    if (this->nodeCounter == 1)
                    {
                        this->first = nullptr;
                        this->nodeCounter--;
                        break;
                    }
                    if (temp == first)
                    {
                        first = temp->next;
                        this->nodeCounter--;
                        break;
                    }
                    prev->next = temp->next;
                    delete temp;
                    this->nodeCounter--;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

void List :: print() const
{
    Node * temp = first;
    cout<<"A lista tartalma : ";
    while (temp!=nullptr)
    {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


List :: ~List()
{
    Node * temp;
    while (first!=nullptr)
    {
        temp = first;
        first = first -> next;
        delete temp;
    }
    this->first = nullptr;
}

