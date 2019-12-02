#include "Szemely.h"

Person::Person(string first, string last, int bDate)
{
	this -> firstName = first;
	this -> lastName = last;
	this->birthDate = bDate;

}

void Person::print(ostream &out)
{
	out << "(" << firstName << " " << lastName << ", " << birthDate << ")" << endl;
}
