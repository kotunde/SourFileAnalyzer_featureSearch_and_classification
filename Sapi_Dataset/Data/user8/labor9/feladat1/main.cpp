#include <cstdlib>
#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include <vector>
using namespace std;

void print( const vector<Szemely * >& szemelyek, ostream& os ) {
    for( unsigned int i=0; i<szemelyek.size(); ++i ) {
        os<< *szemelyek[ i ]<<endl;
    }
}
int main(int argc, char** argv) {
    vector<Szemely * > szemelyek;
    Szemely sz1("Papp","Lorant",1990);
    cout<< sz1<<endl;

    Alkalmazott a1("Janosi", "Emese", 1980, "titkarno");
    Alkalmazott a2("Janosi", "Endre", 1960, "sofor");
    Alkalmazott a3("Egyed", "Emese", 1980, "mernok");

    Alkalmazott a4("Biro", "Zoltan", 1982, "technikus");
    Alkalmazott a5("Abos", "Gergely", 1985, "mernok");

    Manager m1("Barabas","Istvan", 1975, "projektmanager");
    Manager m2("Barabas","Edit", 1975, "HRmanager");

    m1.addAlkalmazott(&a1);
    m1.addAlkalmazott(&a2);
    m1.addAlkalmazott((&a3));

    m2.addAlkalmazott(&a4);
    m2.addAlkalmazott(&a5);

    szemelyek.push_back( &a1 );
    szemelyek.push_back( &a2 );
    szemelyek.push_back( &a3 );
    szemelyek.push_back( &a4 );
    szemelyek.push_back( &a5 );

    szemelyek.push_back( &m1 );
    szemelyek.push_back( &m2 );

    print( szemelyek, cout );

//Athelyezes
    m1.deleteAlkalmazott(&a1);
    m2.addAlkalmazott(&a1);

    cout<<"Athelyezes utan: "<<endl;
    print( szemelyek, cout );
    return (EXIT_SUCCESS);
}
