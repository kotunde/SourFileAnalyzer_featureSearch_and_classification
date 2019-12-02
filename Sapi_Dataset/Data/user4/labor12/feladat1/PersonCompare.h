#ifndef PERSONCOMPARE_H_INCLUDED
#define PERSONCOMPARE_H_INCLUDED

#include"Person.h"

using namespace std;

struct PersonCompare
{
    bool operator()( const Person& p1, const Person& p2)
    {
        if( p1.getFirstName() == p2.getFirstName() )
            return p1.getLastName() < p2.getLastName();
        return p1.getFirstName() < p2.getFirstName();
    }
};

#endif // PERSONCOMPARE_H_INCLUDED
