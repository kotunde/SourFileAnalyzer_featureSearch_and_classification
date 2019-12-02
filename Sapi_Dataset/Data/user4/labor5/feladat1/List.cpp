#include<iostream>
#include "List.h"
using namespace std;

List :: List()
{
    this->first = nullptr;
}

List :: ~List()
{
    while(first != nullptr)
    {
        Node *aux = first;
        first = first->next;
        delete aux;
    }
    first =nullptr;
}

bool List :: exists(int d) const
{
    Node *aux = first;
    while (aux != nullptr )
    {
        if(aux->value ==d)
        {
            return true;
        }
        aux = aux->next;
    }
    return false;

}

int List :: size() const
{
    return this->nodeCounter;
}

bool List :: empty() const
{
    if(nodeCounter == 0)
    {
        return true;
    }
    return false;
}

void List :: insertFirst(int d)
{
    first = new Node(d,first);
    nodeCounter++;
}

void  List :: remove(int d, DeleteFlag df )
{

    switch(df)
    {
    case DeleteFlag :: LESS:
    {
        Node* prev = nullptr;
        Node* cur = first;
        while(cur != nullptr)
        {
            if(cur->value < d)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if(prev == nullptr)
        {
            first = first->next;
            delete cur;
            nodeCounter--;
        }
        else
        {
            if(cur != nullptr)
            {
                prev->next = cur->next;
                delete cur;
                nodeCounter--;
            }
        }
        break;
    }
    case DeleteFlag :: EQUAL:
    {
        Node* prev = nullptr;
        Node* cur = first;
        while(cur != nullptr)
        {
            if(cur->value == d)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if(prev == nullptr)
        {
            first = first->next;
            delete cur;
            nodeCounter--;
        }
        else
        {
            if(cur != nullptr)
            {
                prev->next = cur->next;
                delete cur;
                nodeCounter--;
            }
        }
        break;
    }
    case DeleteFlag :: GREATER:
    {
        Node* prev = nullptr;
        Node* cur = first;
        while(cur != nullptr)
        {
            if(cur->value > d)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if(prev == nullptr)
        {
            first = first->next;
            delete cur;
            nodeCounter--;
        }
        else
        {
            if(cur != nullptr)
            {
                prev->next = cur->next;
                delete cur;
                nodeCounter--;
            }
        }
        break;
    }
    }
}

void List :: print() const
{
    Node *aux = first;
    while (aux != nullptr)
    {
        cout << aux->value<< " ";
        aux = aux->next;

    }
    cout << endl;
}





