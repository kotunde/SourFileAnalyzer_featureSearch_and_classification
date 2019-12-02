#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

const int MAXN = 2000;

int n;
int L[MAXN], P[MAXN], p[MAXN];

bool cmp(const int i, const int j)
{
 	return P[i]*L[j] > P[j]*L[i] || (P[i]*L[j] == P[j]*L[i] && i<j);
}

void main2()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> L[i];
	for (int i = 0; i < n; i++)
		cin >> P[i];
	for (int i = 0; i < n; i++)
		p[i] = i;
	sort(p, p+n, cmp);
	gout;
	for (int i = 0; i < n; i++)
		printf("%d%c", p[i], " \n"[i+1==n]);
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
