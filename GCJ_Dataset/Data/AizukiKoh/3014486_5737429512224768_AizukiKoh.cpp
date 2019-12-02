#include <iostream>
#include <set>

using namespace std;

int solve(int X, multiset<int> S){
	set<int>::iterator it = S.begin();
	set<int>::reverse_iterator rit = S.rbegin();
	int size = S.size();
	int ans = 0;
	while(true){
		if(*rit+*it<=X){
			++rit;
			++it;
			size-=2;
			++ans;
		}else{
			++rit;
			--size;
			++ans;
		}
		if(size<=0){
			return ans;
		}
	}
}

void ans(int x,int y){
	cout << "Case #" << x << ": " << y << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int i = 1;i <= 100;++i){
		int N,X;
		multiset<int> S;
		cin >> N >> X;
		for(int j = 0;j < N;++j){
			int temp;
			cin >> temp;
			S.insert(temp);
		}
		ans(i,solve(X,S));
	}

	return 0;
}
