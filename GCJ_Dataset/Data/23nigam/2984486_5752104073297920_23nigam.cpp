//#include<iostream>
//#include<stdio.h>
//#include<vector>
//#include<sstream>
//#include<string>
//#include<algorithm>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	ifstream in ("in.txt");
//	ofstream out ("out.txt");
//	
//	int testcases;
//	in>>testcases;
//
//
//	for(int testcase=0;testcase<testcases;testcase++)
//	{	
//		int n;
//		in>>n;
//		vector<int> ints(n);
//		bool flag = true;
//		
//		for(int i=0;i<n;i++)
//		{
//			int temp;
//			in>>temp;
//			ints[i] = temp;;
//			if(temp!=i)
//				flag = false;
//			
//		}
//		
//
//		out<<"Case #"<<testcase + 1<<": ";
//		
//		if(!flag)
//			out<<"GOOD";
//		else
//			out<<"BAD";
//
//		out<<endl;
//	}
//	return 0;
//}

#include<iostream>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
#include <fstream>
using namespace std;

int random(int min, int max)
{
	// x is in [0,1[
	double x = rand()/static_cast<double>(RAND_MAX); 

	// [0,1[ * (max - min) + min is in [min,max[
	int that = min + static_cast<int>( x * (max - min) );

	return that;
}

int main()
{
	ofstream out ("out.txt");
	ofstream out2 ("out2.txt");
	ofstream out3 ("out3.txt");

	int arr[5];

	for(int j=0;j<100;j++)
	{

		for(int i=0;i<5;i++)
			arr[i] = i;

		for(int i=0;i<5;i++)
		{
			int p = random(i,5);
			swap(arr[i],arr[p]);
		}

		for(int i=0;i<5;i++)
			out<<arr[i]<<" ";

		for(int i=0;i<5;i++)
			arr[i] = i;

		for(int i=0;i<5;i++)
		{
			int p = random(0,5);
			swap(arr[i],arr[p]);
		}

		for(int i=0;i<5;i++)
			out2<<arr[i]<<" ";

		out<<endl;
		out2<<endl;
	}

	for(int i=1;i<121;i++)
	{
		out3<<"Case #"<<i<<": ";

		int p=rand() % 2;

		if(p == 0)
			out3<<"GOOD"<<endl;
		else
			out3<<"BAD"<<endl;
	}

	return 0;
}