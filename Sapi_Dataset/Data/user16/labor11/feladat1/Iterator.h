#ifndef ITERATOR_H
#define ITERATOR_H

template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator
{
public:
    Iterator(OrderedList<T,LessComp,Equal> & x) : list(x), act(list.first)
    {

    }
    bool hasNext();
    T next();

private:

    OrderedList<T,LessComp,Equal> & list;
    class OrderedList<T,LessComp,Equal>::Node * act;
};

template <class T, class LessComp, class Equal >
bool Iterator<T,LessComp,Equal> :: hasNext ()
{
    if (act->next!=nullptr)
        return true;
    return false;
}

template <class T, class LessComp, class Equal >
T Iterator<T,LessComp,Equal> :: next()
{
    class OrderedList<T,LessComp,Equal>::Node * temp = act;
    act=act->next;
    return temp->value;
}

#endif // ITERATOR_H
