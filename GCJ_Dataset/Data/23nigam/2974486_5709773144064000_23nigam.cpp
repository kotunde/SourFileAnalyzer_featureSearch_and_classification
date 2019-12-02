#include<iostream>
using namespace std;

int main()
{
	int testcases;
	cin>>testcases;
	float C,F,X,max,time,CP,new_CP;
	bool flag;

	for(int i=0;i<testcases;i++)
	{
		cin>>C;
		cin>>F;
		cin>>X;
		flag = true;
		time=0,CP=2,new_CP=0,max = X/CP;
		while(flag)
		{
			new_CP = CP + F;

			time = time + C/CP;

			if(X < C)
			{
				cout<<"Case #"<<i + 1<<": "<< max<<endl;
				break;
			}

			float chk = time + X/new_CP;
			
			if( chk > max)
			{
				cout<<"Case #"<<i + 1<<": "<< max<<endl;
				flag = false;
			}
			
			max = chk;

			CP = new_CP;
		}
		
	}
	return 0;
}