#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int Cards[16];

void readCard(Cards &card, ifstream &ifs) {
	string str;
	for (int i = 0; i < 16; ++i) {
		ifs >> str;
		card[i] = atoi(str.c_str());
	}
}

int checkCards(Cards card1, Cards card2, int first, int second, int &flag) {
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (card1[first * 4 + i] == card2[second * 4 + j]) {
				ans = card1[first * 4 + i];
				flag++;
			}
			if (flag >= 2) {
				return ans;
			}
		}
	}
	return ans;
}

void outputAnswer(int x, int flag, int ans) {
	cout << "Case #" << x << ": ";
	switch (flag) {
	case 0:
		cout << "Volunteer cheated!\n";
		break;
	case 1:
		cout << ans << "\n";
		break;
	case 2:
		cout << "Bad magician!\n";
		break;
	}
}

int main() {
	ifstream ifs("A-small-attempt0.in");
	if (ifs.fail()) {
		cerr << "File do not exist.\n";
		exit(0);
	}

	string str;

	ifs >> str;
	int t = atoi(str.c_str());
	Cards test1;
	Cards test2;

	for (int i = 0; i < t; ++i) {
		int first, second;
		ifs >> str;
		first = atoi(str.c_str());
		readCard(test1, ifs);
		ifs >> str;
		second = atoi(str.c_str());
		readCard(test2, ifs);

		int flag = 0;
		int ans = checkCards(test1, test2, first - 1, second - 1, flag);

		outputAnswer(i + 1, flag, ans);
	}
	cout.flush();

	return 0;
}
