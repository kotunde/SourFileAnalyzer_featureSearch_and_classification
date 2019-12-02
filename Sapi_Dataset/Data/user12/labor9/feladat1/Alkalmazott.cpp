#include <cstdlib>
#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>

Alkalmazott::Alkalmazott(string vezetek, string kereszt, int ev, string munka):Szemely(vezetek,kereszt,ev){
this->munkakor=munka;
}
void Alkalmazott::print(ostream& out){
Szemely:print(out);
cout << this->munkakor;
out << endl;

}
