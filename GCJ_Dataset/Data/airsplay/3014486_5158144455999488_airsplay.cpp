#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream fin("1.in");
	ofstream fout("1.out");

	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << ' ';
	}


}
