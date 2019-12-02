#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "person.h"

class Alkalmazott: public Szemely{
protected:
    string munkakor;

public:
    Alkalmazott(string, string, int, string);
    void virtual print(ostream&) const;
};

#endif // EMPLOYEE_H_INCLUDED
