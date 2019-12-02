#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED

#include <functional>
#include <iostream>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        bool isEmpty() const;
        void insert(const T&);
        void remove(const T&);
        int size() const;
        bool find(const T&) const;
        void listItems(ostream& os=cout);
        struct Node{
            T value;
            Node* next;
            Node(T v=0, Node* n=nullptr){
                value=v;
                next=n;
            }
        };
    private:

        Node* first;
        int numElements;
};

template <class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList(){
    this->numElements=0;
    this->first=nullptr;
}

template <class T, class LessComp, class Equal >
OrderedList<T, LessComp, Equal>::~OrderedList(){
    Node* node=this->first;
    Node* prev=nullptr;
    while(node!=nullptr){
        prev=node;
        node=node->next;
        delete prev;
    }
}

template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() const{
    if(this->numElements==0){
        return true;
    }
    return false;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T& elem){
    Node* uj=new Node(elem, nullptr);
    Node* node=this->first;
    Node* prev=nullptr;
    while(node!=nullptr && LessComp()(node->value, elem)){//node->value < elem
        prev=node;
        node=node->next;
    }
    if(prev==nullptr){
        uj->next = first;
        this->first=uj;

    }
    else{
        uj->next=node;
        prev->next=uj;
    }
    this->numElements++;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T& elem){
    Node* node=this->first;
    Node* prev=nullptr;
    while(node!=nullptr){
        if(Equal()(node->value,elem)){
            if(prev==nullptr){
                this->first=node->next;
            }
            else{
                prev->next=node->next;
            }
            delete node;
            this->numElements--;
            break;
        }
        prev=node;
        node=node->next;
    }
}

template <class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const{
    return this->numElements;
}

template <class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T& elem) const{
    Node* node=this->first;
    for(int i=0; i<this->numElements; i++){
        if(Equal()(node->value,elem)){
            return true;
        }
        node=node->next;
    }
    return false;
}

template <class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream& os){
    Node* node=this->first;
    for(int i=0; i<this->numElements; i++){
        os<<node->value<<" ";
        node=node->next;
    }
    os<<endl;
}

#endif // ORDEREDLIST_H_INCLUDED
