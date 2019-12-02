#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int pow[11]={1,2,4,8,16,32,64,128,256,512,1024};
int main() 
{
	int t,n,l,ans,cr1,cr0,ch0,ch1,c,x,cs=0;
	bool chk;
	string str;
	cin>>t;
	set<int> s;
	while(t--)
	{
		cout<<"Case #"<<++cs<<": "; 
		cin>>n>>l;
		chk=true;
		int arr[n],req[n];
		for(int i=0;i<n;i++)
		{
			cin>>str;
			arr[i]=0;
			c=0;
			for(int j=l-1;j>=0;j--)
			{
				if(str[j]=='1')
					arr[i]+=pow[c];
				c++;
			}
		}
		for(int i=0;i<n;i++)
		{
			cin>>str;
			req[i]=0;
			c=0;
			for(int j=l-1;j>=0;j--)
			{
				if(str[j]=='1')
					req[i]+=pow[c];
				c++;
			}
		}
		sort(arr,arr+n);
		sort(req,req+n);
		for(int i=0;i<n;i++)
		{
	//		cout<<arr[i]<<" "<<req[i]<<endl;
			if(arr[i]!=req[i])
			{
				chk=false;
		//		break;
			}
		}
		if(chk)
		{
			cout<<0<<endl;
			continue;
		}
		ans=n+1;
		int hlp[n];
//		cout<<pow[l]-1<<endl;
		for(int i=1;i<=pow[l]-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				hlp[j]=arr[j];
				hlp[j]^=i;
			}
			chk=true;
			sort(hlp,hlp+n);
			for(int i=0;i<n;i++)
			{
				if(hlp[i]!=req[i])
				{
					chk=false;
					break;
				}
			}
			c=0;
			if(chk)
			{
				x=i;
				while(x)
				{
					if(x%2==1)
						c++;
					x/=2;
				}
				if(c<ans)
					ans=c;
			}
		}
		if(ans==n+1)
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}