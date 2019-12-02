#include "OrderedList.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main()
{
    OrderedList<int> l;
    for( int i=0; i<10; ++i )
    {
        int v = rand() % 10;
        l.insert( v );
    }
    l.listItems(cout);

    cout<<"\nList using iterator: ";
    Iterator<int> it(l);
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;

    for( int i=0; i<10; ++i )
    {
        int t = rand() % 10;
        cout<<"\nTorlendo: "<<t<<endl;
        l.remove( t );
        l.listItems(cout);
    }
    return 0;
}
