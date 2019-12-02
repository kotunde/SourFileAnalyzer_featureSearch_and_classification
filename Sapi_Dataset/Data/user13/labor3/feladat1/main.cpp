#include <cstdlib>
#include <iostream>
#include "PontHalmaz.h" 

using namespace std; 
int main(int argc, char** argv) { 
	int n = 2;     
	cout << "Pontok\tMinTav\tMaxTav\t#tavolsagok\t#kulonbozotavolsagok" << endl;  
	for (int i = 0; i < 12; ++i) {
		PontHalmaz ph(n);        
		cout << n << "\t" << ph.minTavolsag() << "\t" << ph.maxTavolsag() << "\t";       
		cout << ph.tavolsagokSzama() << "\t" << ph.kulonbozoTavolsagokSzama() << endl;        
		n = n << 1; }     
	return 0; 
}