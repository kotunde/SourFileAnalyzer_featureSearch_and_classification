#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	//Permut I.
	//string words[] = { "one","two","three","four","five" };

	//sort(words,words+5);
	//cout << "first permutacio: ";
	//for (auto x : words) {
	//	cout << x << " ";
	//}
	//cout << endl;
	//while ( next_permutation(words,words + 5) ) {
	//	cout <<  " next permutacio: ";
	//	for (int i = 0; i < 5; ++i) {
	//		cout << words[i] <<" ";
	//	}
	//	cout << endl;
	//}
	//Permut II.
	/*string x[] = { "A", "E", "K", "M", "T" };
	int num = 1;
	cout << num << " " << x[0] << x[1] << x[2] << x[3] << x[4] << endl;
	num++;
	while (num<121) {
		next_permutation(x, x + 5);
		cout << num << " " << x[0] << x[1] << x[2] << x[3] << x[4] << endl;
		num++;
	}*/
	//Fuggvenyobjektum III.
	ifstream file;
	file.open("be.txt");
	string line;
	if (file.is_open()) {
		while (getline (file, line) ) {
			cout << line << "\n";
		}
		file.close();
	}



	cin.get();
	return(EXIT_SUCCESS);
}