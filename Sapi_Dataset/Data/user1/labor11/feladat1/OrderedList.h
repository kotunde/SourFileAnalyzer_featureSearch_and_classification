#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED
#include <functional>
#include <iostream>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T>>
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;
        Node(T v, Node* n) : value(v), next(n) {}
    };

    Node* first;
    int numElements;
public:
    OrderedList();
    ~OrderedList();
    bool isEmpty();
    void insert(const T&);
    void remove(const T&);
    int size();
    bool find(const T&) const;
    void listItems(ostream&);
};

template<class T, class LessComp, class Equal>
OrderedList<T,LessComp,Equal>::OrderedList(){
    this->first = nullptr;
    this->numElements = 0;
}

template<class T, class LessComp, class Equal>
OrderedList<T,LessComp,Equal>::~OrderedList(){
}

template<class T, class LessComp, class Equal>
bool OrderedList<T,LessComp,Equal>::isEmpty(){
    if (this->numElements == 0){return true;}
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T,LessComp,Equal>::insert(const T& value){
    Node* uj = new Node(value,nullptr);
    Node* act = this->first;
    Node* prev = nullptr;
    while (act != nullptr && LessComp()(act->value, value)){
        prev = act;
        act = act->next;
    }
    if (prev == nullptr){
        this->first = uj;
        ++this->numElements;
    }
    else {
        prev->next = uj;
        uj->next = act;
        ++this->numElements;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T,LessComp,Equal>::remove(const T& value){
    Node* act = this->first;
    Node* prev = nullptr;
    while (act != nullptr && !Equal()(act->value,value)){
        prev = act;
        act = act->next;
    }
    prev->next = act->next;
    --this->numElements;
}

template<class T, class LessComp, class Equal>
int OrderedList<T,LessComp,Equal>::size(){
    return this->numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T,LessComp,Equal>::find(const T& value) const{
    Node* act = this->first;
    while (act != nullptr && !Equal()(act->value,value)){
        act = act->next;
    }
    if (act == nullptr){return false;}
    return true;
}

template<class T, class LessComp, class Equal>
void OrderedList<T,LessComp,Equal>::listItems(ostream& os){
    Node* act = this->first;
    while (act != nullptr){
        os << act->value << " ";
        act = act->next;
    }
}

template <class T, class LessComp = less<T>, class Equal = equal_to<T>>
class Iterator{
private:
    OrderedList<T,LessComp,Equal>& list;
    OrderedList<T,LessComp,Equal>::Node* act;
public:
    Iterator(OrderedList<T,LessComp,Equal>&);
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
Iterator<T,LessComp,Equal>::Iterator(OrderedList<T,LessComp,Equal>& l){
    this->list = l;
    this->act = l->first;
}

template<class T, class LessComp, class Equal>
bool Iterator<T,LessComp,Equal>::hasNext(){
    if (this->act->next == nullptr){return false;}
    return true;
}

template<class T, class LessComp, class Equal>
T Iterator<T,LessComp,Equal>::next(){
    return this->act->next;
}


#endif // ORDEREDLIST_H_INCLUDED
