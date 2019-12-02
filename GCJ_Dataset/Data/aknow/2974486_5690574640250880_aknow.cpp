#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

int R, C, M;
char board[51][51];

// xxxxx
// xxxxx
// xxxxx

void clear() {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      board[i][j] = '.';
    }
  }
}

bool tryH(int remain) {
  int r, c, n;
  r = c = 0;

  clear();
  while (remain) {
    if (r == R-2) {
      if (remain % 2) return false;
      n = remain / 2;
      if (n == C - 1) return false;

      for (int i = 0; i < n; ++i) {
        board[r][i] = '*';
        board[r+1][i] = '*';
      }
      return true;
    }

    if (remain >= C) n = C;
    else if (remain == C-1) n = C-2;
    else n = remain;

    for (int i = 0; i < n; ++i) board[r][i] = '*';
    remain -= n;

    r++;
    if (r == R) return false;
  }
  return true;
}

bool tryV(int remain) {
  int r, c, n;
  r = c = 0;

  clear();
  while (remain) {
    if (c == C-2) {
      if (remain % 2) return false;
      n = remain / 2;
      if (n == R - 1) return false;

      for (int i = 0; i < n; ++i) {
        board[i][c] = '*';
        board[i][c+1] = '*';
      }
      return true;
    }

    if (remain >= R) n = R;
    else if (remain == R-1) n = R-2;
    else n = remain;

    for (int i = 0; i < n; ++i) board[i][c] = '*';
    remain -= n;

    c++;
    if (c == C) return false;
  }

  return true;
}

void fillRow(int remain) {
  clear();
  for (int i = 0; i < remain; ++i) {
    board[0][i] = '*';
  }
}

void fillCol(int remain) {
  clear();
  for (int i = 0; i < remain; ++i) {
    board[i][0] = '*';
  }
}

void fillAll() {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      board[i][j] = '*';
    }
  }
}

void showBoard() {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (i == R-1 && j == C-1) cout << "c";
      else cout << board[i][j];
    }
    cout << endl;
  }
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d:\n", cc);
        cin >> R >> C >> M;

        if (M == R * C - 1) {
          fillAll();
          showBoard();
        } else if (R == 1) {
          fillRow(M);
          showBoard();
        } else if (C == 1) {
          fillCol(M);
          showBoard();
        } else if (tryH(M) || tryV(M)) {
          showBoard();
        } else {
          cout << "Impossible" << endl;
        }
    }

    return 0;
}
