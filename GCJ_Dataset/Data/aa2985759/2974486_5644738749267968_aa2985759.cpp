#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>

using namespace std;

double a[1100];
double b[1100];

int get(int n)
{
    sort(a,a+n);
    sort(b,b+n);

    int i,j,ans=0;
    
    j=0;
    for(i=0;i<n;i++)
    {
	while(j<n&&a[j]<b[i])
	    j++;
	if(j>=n)
	    return ans;
	ans++;
	j++;
    }
    return ans;
}
int get1(int n)
{
    sort(a,a+n);
    sort(b,b+n);

    int i,j,ans=0;

    j=n-1;
    for(i=n-1;i>=0;i--)
    {
	while(j>=0&&a[j]>b[i])
	    j--;
	if(j<0)
	    return ans;
	ans++;
	j--;
    }
    return ans;
}
int main()
{
    int n,i,j,k;

    int t,ii=0;

    freopen("d.in","r",stdin);
    freopen("d.txt","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%lf",&a[i]);
	for(i=0;i<n;i++)
	    scanf("%lf",&b[i]);
	printf("Case #%d: %d %d\n",++ii,get(n),n-get1(n));
    }
}
