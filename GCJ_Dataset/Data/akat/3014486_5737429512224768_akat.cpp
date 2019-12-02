#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{
	int l,r,n,x,br=0,a[10004],i;
	cin>>n>>x;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	l=0;
	r=n-1;
	while(l<=r)
	{
		if(a[r]+a[l]<=x)
		{
			br++;
			l++;
			r--;
		}
		else
		{
			br++;
			r--;
		}
	}
	cout<<br<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
