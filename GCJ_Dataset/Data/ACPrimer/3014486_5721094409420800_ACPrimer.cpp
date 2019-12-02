#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int a[maxn],b[maxn],L[maxn/2+1],R[maxn/2+1];
int cnt;
void merge(int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int i,j,k;
	memcpy(L,a+p,n1*sizeof(int));
	memcpy(R,a+q+1,n2*sizeof(int));
	L[n1]=R[n2]=inf;
	i=j=0;
	for(k=p;k<=r;k++)
		if(L[i]<=R[j])
			a[k]=L[i++];
		else
		{
			a[k]=R[j++];
			cnt+=n1-i;
		}
}
void merge_sort(int p,int r)
{
	int q=(p+r)/2;
	if(p<r)
	{
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}
}
int Abs(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
    int T,n,ncase=0;
    cin>>T;
    while(T--){
        cin>>n;
        int m=0,id=0,ans=inf;
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) if(b[i]>m)
        {
            m=b[id=i];
        }
        for(int i=id-1;i>=0;i--) swap(b[i],b[i+1]);
        for(int i=0;i<n;i++)
        {
            int cur=Abs(i-id);
            if(i!=0) swap(b[i],b[i-1]);
            //for(int i=0;i<n;i++) printf("%d ",b[i]);
            //printf("\n");
            memcpy(a,b,sizeof(a));
            cnt=0;
            merge_sort(0,i);
            cur+=cnt;
            for(int j=i;j<n;j++) a[j]=-a[j];
            cnt=0;
            merge_sort(i,n-1);
            cur+=cnt;
            if(cur<ans) ans=cur;
        }
        printf("Case #%d: %d\n",++ncase,ans);
    }
    return 0;
}
/*
2
3
1 2 3
5
1 8 10 3 7
*/
