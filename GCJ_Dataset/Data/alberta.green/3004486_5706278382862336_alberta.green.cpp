#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
#include <algorithm>
#include <string>
#include <sstream> 

using namespace std;

int main()
{
  int T;
  int x = 0;
  cin>>T;
  while(++x&&(T-x+1))
    {
      cout<<"CASE #"<<x<<": ";
	  int P, Q;
	  cin>>P;
	  cin.ignore(1,'\\');
	  cin>>Q;
	  int power = 0;
	  int temp = 1;
	  while (temp < Q)
	  {
		  temp*=2;
		  power++;
		  if (temp == Q)
		  {
			  break;
		  }
	  }
	  if (temp != Q)
		  cout<<"impossible"<<endl;
	  else
	  {
		  int sep = 0;
		  while (temp > P)
		  {
			  sep++;
			  temp/=2;
		  }
		  cout<<sep<<endl;
	  }
    }
  return 0;
}