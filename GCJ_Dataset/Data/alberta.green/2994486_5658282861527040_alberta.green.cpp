#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  int x = 0;
  cin>>T;
  while(++x&&(T-x+1))
    {
      cout<<"CASE #"<<x<<": ";
	  int A,B,K,n;
	  cin>>A>>B>>K;
	  n = 0;
	  for (int i = 0; i < A; i++)
		  for (int j = 0; j < B; j++)
			  if ((i&j) < K && (i&j) >= 0)
				  n++;
	  cout<<n<<endl;
    }
  return 0;
}