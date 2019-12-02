#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

double nemHatekonyMedianParos(vector<int>);
int nemHatekonyMedianParatlan(vector<int>);
double HatekonyMedianParos(vector<int>);
int HatekonyMedianParatlan(vector<int>);
double median(vector <double>);
double nemHatekonyMedian(vector<double>);

int main() {
	ifstream fin("inputParos.txt");   if (!fin.is_open()) { cout << "error while opening the file!"; }
	//file.open("input.txt");
	
	vector <double> numb;
	int n;	//number of elements 
	fin >> n;
	double temp;
	for (int i = 0; i < n; ++i) {				//putting the elements in the vector
		fin >> temp;
		numb.push_back(temp);
	}
	cout << "The array: ";
	for (int i = 0; i < n; ++i) {				//writing it just to check
		cout << numb[i] << ' ';
	}
	//cout << "vector.size= " << numb.size();
	cout << endl;
	cout << "Nemhatekony modszerrel kiszamitott median: " << nemHatekonyMedian(numb) << endl;
	cout << "Hatekony modszerrel kiszamitott median : "<< median(numb) << endl;

		
	fin.close();
	cin.get();
	return (EXIT_SUCCESS);
}

double median(vector <double> szamok) throw (domain_error) {
	if (szamok.size()==NULL) { throw domain_error("ures tomb"); }
	
	nth_element(szamok.begin(), szamok.begin() + szamok.size() / 2, szamok.end());

	if (szamok.size() % 2 == 1) {										//paratlan
		return szamok[(szamok.size() / 2) + 1];
	}

	if (szamok.size() % 2 == 0) {
		return (szamok[(szamok.size() / 2)] + szamok[(szamok.size() / 2) - 1]) / 2;		//paros
	}
}

double nemHatekonyMedian(vector<double>szamok) throw (domain_error) {
	if (szamok.size() == NULL) { throw domain_error("ures tomb"); }

	sort(szamok.begin(), szamok.end());

	if (szamok.size() % 2 == 1) {
		return szamok[(szamok.size() / 2) + 1];
	}

	if (szamok.size() % 2 == 0) {
		return (szamok[(szamok.size() / 2)] + szamok[(szamok.size() / 2) - 1]) / 2;
	}
}

//*******************************************************************************************************

int nemHatekonyMedianParatlan(vector<int>szamok) throw (domain_error){
	if (!szamok.size()) { throw domain_error("ures tomb"); }
	sort(szamok.begin(),szamok.end());
	cout << "The sorted array: " ;
	for (int i = 0; i < szamok.size(); ++i) {				//writing it just to check
		cout << szamok[i] << ' ';
	}
	cout << endl;
	return szamok[(szamok.size() / 2) + 1];				 //kozepso elem, paratlan szamu sorozat eseten
}

double nemHatekonyMedianParos(vector<int>szamok) throw (domain_error) {
	if (!szamok.size()) { throw domain_error("ures tomb"); }
	sort(szamok.begin(), szamok.end());
	cout << "The sorted array: " ;
	for (int i = 0; i < szamok.size(); ++i) {				//writing it just to check
		cout << szamok[i] << ' ';
	}
	cout << endl;
	return (szamok[(szamok.size() / 2)]+ szamok[(szamok.size() / 2) - 1]) /(double)2;
}
