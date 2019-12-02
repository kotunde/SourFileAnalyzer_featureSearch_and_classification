#include<iostream>
using namespace std;

int main()
{
	int testcases,flag=0;
	cin>>testcases;
	if(testcases > 100)
		testcases = 100;
	int deck1[16],deck2[16],ans,ans1,ans2;

	for(int i=0;i<testcases;i++)
	{
		cin>>ans1;
		for(int i=0;i<16;i++)
		{
			cin>>deck1[i];
		}
		cin>>ans2;
		for(int i=0;i<16;i++)
		{
			cin>>deck2[i];
		}
		for(int i=0;i<4;i++)
		{
			int chk=deck1[(ans1-1)*4 + i];
			for(int i=0;i<4;i++)
			{
				if(chk == deck2[(ans2-1)*4 + i])
				{
					flag++;
					ans = chk;
				}
			}
		}
		
		if(flag == 0)
			cout<<"Case #"<<i + 1<<": Volunteer cheated!"<<endl;
		else if(flag == 1)
			cout<<"Case #"<<i + 1<<": "<<ans<<endl;
		else
		{
			cout<<"Case #"<<i + 1<<": Bad magician!"<<endl;
		}
		flag = 0;
	}
	return 0;
}