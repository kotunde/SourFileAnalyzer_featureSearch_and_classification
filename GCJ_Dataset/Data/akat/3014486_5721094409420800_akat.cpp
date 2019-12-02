#include<iostream>
using namespace std;
int dpl[1010],dpr[1010];
void solve()
{
	int n,i,j,b[1010],a[1010],o=0,br=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return;
	}
	dpl[0]=0;
	for(i=1;i<n;i++)
	{
		br=0;
		for(j=i;j>0;j--)
			if(b[j]<b[j-1])
			{
				swap(b[j],b[j-1]);
				br++;
			}
		dpl[i]=dpl[i-1]+br;
	}
	for(i=0;i<n;i++)
		b[i]=a[i];
	dpr[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		br=0;
		for(j=i;j<n-1;j++)
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
				br++;
			}
		dpr[i]=dpr[i+1]+br;
	}
	o=dpl[0]+dpr[1];
	for(i=1;i<n-1;i++)
		o=min(o,dpl[i]+dpr[i+1]);
	cout<<o<<endl;
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
