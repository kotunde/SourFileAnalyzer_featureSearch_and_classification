#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int cont;
int mx;
int m, n;
string s[10];
vector<string> groups[5];

int trieSize(int index) {
  set<string> st;
  //cout << "Trie" << endl;
  for (int i=0; i<groups[index].size(); ++i) {
    string tmp = groups[index][i];
    //cout << tmp << endl;
    for (int j=1; j<=tmp.length(); ++j) {
      st.insert(tmp.substr(0,j));
    }
  }
  if (st.size() == 0) return 0;
  //cout << st.size() << endl;
  return 1 + st.size();
}

void findComb(int index) {
  if (index == m) {
    int size = 0;
    for (int i=0; i<n; ++i) {
      size += trieSize(i);
    }
    if (size > mx) {
      mx = size;
      cont = 1;
    } else if (size == mx) ++cont;
  } else {
    for (int i=0; i<n; ++i) {
      vector<string> tmp = groups[i];
      groups[i].push_back(s[index]);
      findComb(index+1);
      groups[i] = tmp;
    }
  }
}

void solve() {
  cin >> m >> n;
  cont = mx = 0;
  for (int i=0; i<n; ++i) groups[i].clear();
  for (int i=0; i<m; ++i) {
    cin >> s[i];
  }
  findComb(0);
  cout << mx << " " << cont << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

