#include "Felveteli.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main() {
	Felveteli felv1 = Felveteli(2);
	Student diak1 = Student("Elso", "Diak", 8.8);
	Student diak2 = Student("Masodik", "Diak", 9.8);
	Student diak3 = Student("Elso", "Diak", 5.1);
	Student diak4 = Student("Negyedik", "Diak", 3.2);
	felv1.beiratkozas(diak1);
	felv1.beiratkozas(diak2);
	felv1.beiratkozas(diak3);
	felv1.beiratkozas(diak4);
	felv1.rendezesABC();
	cout << "Beiratkozott Student-ek ABC sorrendbe:\n\n";
	felv1.print();
	cout << "\nBejutott Student-ek ABC sorrendben:\n\n";
	felv1.bejutottak();
	
	cout << "Masodik konstruktor:\n";
	Felveteli felv2 = Felveteli("input.txt");
	felv2.print();
	cout << "\nBejutottak:\n\n" ;
	felv2.bejutottak();
	felv2.kiirFileba("kimenet.txt");

}