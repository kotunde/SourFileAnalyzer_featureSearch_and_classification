#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int W = 105;
const int H = 505;

int w, h;
int river[W][H];
int visited[W][H];
int dir[W][H];
int t;
int x[W*H];
int y[W*H];
int qa, qb;

enum R {
  O = 0,
  X = 1,
  E = 2,
  V = 3,
  S = 4,
  N = 5,
  Y = 6
};

void init() {
  int b;
  scanf("%d%d%d", &w, &h, &b);
  for (int i = 0; i <= w + 1; ++i) {
    for (int j = 0; j <= h + 1; ++j) {
      visited[i][j] = 0;
      river[i][j] = O;
    }
  }
  for (int i = 0; i <= w + 1; ++i) {
    river[i][0] = X;
    river[i][h + 1] = Y; 
  }
  for (int i = 0; i <= h + 1; ++i) {
    river[0][i] = river[w + 1][i] = X;
  }

  while (b--) {
    int x0, y0, x1, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    if (x1 < x0) swap(x0, x1);
    if (y1 < y0) swap(y0, y1);
    for (int i = x0 + 1; i <= x1 + 1; ++i) {
      for (int j = y0 + 1; j <= y1 + 1; ++j) {
        river[i][j] = X;
      }
    }
  }
  t = 0;
}

void insert(int i, int j, R r) {
  if (visited[i][j] == t) return;
  visited[i][j] = t;
  x[qb] = i;
  y[qb] = j;
  dir[i][j] = r;
  ++qb;
}

void goBack(int &i, int &j) {
    switch (dir[i][j]) {
      case V:
      ++i;
      break;
      case E:
      --i;
      break;
      case N:
      --j;
      break;
      case S:
      ++j;
      break;
      default:
      break;
    }
}

bool update(int i, int j, bool cross) {
  if (river[i][j] == Y) return false;
  if (river[i][j] == O || cross) {
    river[i][j] = dir[i][j];
    return false;
  }
  return true;
}

void finish(int i, int j) {
  //printf("finish(%d,%d)\n", i, j);
  bool cross = false;
  while (dir[i][j] != X) {
    //printf("(%d,%d) %d\n", i, j, (int)dir[i][j]);
    cross = update(i, j, cross);
    goBack(i, j);
  }
}

int flow(int i) {
  //printf("flow(%d)\n", i);
  int j = 1;
  ++t;
  qa = qb = 0;
  insert(i, j, X);
  while (qa < qb) {
    i = x[qa];
    j = y[qa];
    ++qa;
    switch (river[i][j]) {
      case O:
      insert(i, j + 1, N);
      insert(i + 1, j, E);
      insert(i - 1, j, V);
      insert(i, j - 1, S);
      break;
      case V:
      insert(i + 1, j, E);
      break;
      case E:
      insert(i - 1, j, V);
      break;
      case N:
      insert(i, j - 1, S);
      break;
      case S:
      insert(i, j + 1, N);
      break;
      case X:
      break;
      case Y:
      finish(i, j);
      return 1;
    }
  }
  return 0;
}

void solve() {
  init();
  int ret = 0;
  for (int i = 1; i <= w; ++i) {
    ret += flow(i);
  }
  printf("%d\n", ret);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
