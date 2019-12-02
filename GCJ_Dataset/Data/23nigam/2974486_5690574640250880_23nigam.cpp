#include<iostream>
#include <math.h>
using namespace std;

int main()
{
	int testcases;
	cin>>testcases;
	float M,R,C;
	bool flag;

	for(int i=0;i<testcases;i++)
	{
		cin>>R;
		cin>>C;
		cin>>M;
		flag = true;
		cout<<"Case #"<<i + 1<<":"<<endl;

		int temp = R*C - M;

		if(R==1 || C==1)
		{
			for(int j=0;j<R;j++)
			{
				for(int k=0;k<C;k++)
				{
					if(j==0 && k==0)
					{
						cout<<"c";
						temp--;
					}
					else if(temp != 0)
					{
						cout<<".";
						temp--;
					}
					else
					{
						cout<<"*";
					}
				}
				if(j!=R-1)
					cout<<endl;
			}
		}
		else
		{
			if(temp == 2 || temp == 3)
				cout<<"Impossible";
			else
			{
				
				
				int place = (-1+sqrt(1 + 8*temp))/2;
				if(place < 0)
					place = (-1-sqrt(1 + 8*temp))/2;
					
				for(int j=0;j<R;j++)
				{
					for(int k=0;k<C;k++)
					{
						if(j==0 && k==0)
						{
							cout<<"c";
							temp--;
						}
						else if(k<place && temp>0)
						{
							cout<<".";
							temp--;
						}
						else if(M>0)
						{
							cout<<"*";
							M--;
						}
						else
						{
							cout<<".";
						}
					}
					if(j!=R-1)
						cout<<endl;
				}
			}

		}
		if(i!=testcases-1)
			cout<<endl;
	}
	return 0;
}