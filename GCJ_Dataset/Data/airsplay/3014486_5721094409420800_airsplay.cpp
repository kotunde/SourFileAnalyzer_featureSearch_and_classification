#include<iostream>
#include<fstream>
using namespace std;
int a[100000];
void exchange(int x){
	int tmp = a[x];
	a[x] = a[x+1];
	a[x+1] = tmp;
}
int main(){
	ifstream fin("2.in");
	ofstream fout("2.out");

	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << ' ';
		fin >> n;
		for (int i = 1; i <= n; i++){
			fin >> a[i];
		}

		int iMax = 0;
		int posMax = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] > iMax ){
				iMax = a[j];
				posMax = j;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = posMax; )
		}
	}


}

