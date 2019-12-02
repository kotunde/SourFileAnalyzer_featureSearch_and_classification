#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
long long mod=1000000007;
int main() 
{
	long long t,n,tst[26],ans,cas=0,mul[26];
	bool chk;
	vector<string> v;
	set<char> st;
	string s;
	char a;
	cin>>t;
	while(t--)
	{
		v.clear();
		for(int i=0;i<26;i++)
			mul[i]=0;
		printf("Case #%d: ",++cas);
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			st.clear();
			for(int i=0;i<s.size();i++)
				st.insert(s[i]);
			if(st.size()==1)
				mul[s[0]-'a']++;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		ans=0;
		do 
		{
		    s="";
		    for(int i=0;i<n;i++)
		    	s+=v[i];
		    for(int i=0;i<26;i++)
		    	tst[i]=1;
		    chk=true;
		    a=s[0];
		    for(int i=1;i<s.length();i++)
		    {
		    	if(tst[s[i]-'a']==0)
		    	{
		    		chk=false;
		    		break;
		    	}
		    	if(s[i]!=a)
		    	{
		    		tst[a-'a']=0;
		    		a=s[i];
		    	}
		    }
		    if(chk)
		    	ans++;
		} while (next_permutation(v.begin(),v.end()));
		for(int i=0;i<26;i++)
		{
			for(int j=2;j<=mul[i];j++)
				ans=(ans*j)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}