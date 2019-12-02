#include<iostream>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int testcases;
	cin>>testcases;

	for(int testcase=0;testcase<testcases;testcase++)
	{	
		int n,l;
		cin>>n;
		cin>>l;
		//cout<<n<<endl<<l<<endl;

		long long sum1=0,sum2=0;
		
		for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			sum1 = sum1 + temp;
			
		}
		
		for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			sum2 = sum2 + temp;
		}
		

		cout<<"Case #"<<testcase + 1<<": ";
		
		//cout <<"'"<<sum1 - sum2<<"'";
		if(l < sum1-sum2)
			cout<<"NOT POSSIBLE";
		else if(sum1>sum2)
			cout<<sum1 - sum2;
		else
			cout<<sum2-sum1;

		cout<<endl;
	}
	return 0;
}