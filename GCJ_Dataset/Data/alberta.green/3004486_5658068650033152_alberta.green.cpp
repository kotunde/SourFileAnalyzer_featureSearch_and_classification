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
	  int N, M, K;
	  cin>>N>>M>>K;
	  if (K <= 4 || N <= 2 || M <= 2)
		  cout<<K<<endl;
	  else if (M*N<=K+4)
		  cout<<2*(M-2)+2*(N-2)<<endl;
	  else
	  {
		  if (N > M)
		  {
			  int temp = N;
			  N = M;
			  M = temp;
		  }

		  int n = 2;
		  int m = 3;
		  while (n*m-3 < K)
		  {
			  if (m == n || n == N)
				  m++;
			  else
				  n++;

		  }
		  if (n*m-3 == K)
			cout<<2*(m-2)+2*(n-2)+1<<endl;
		  else
			cout<<2*(m-2)+2*(n-2)<<endl;

	  }
    }
	return 0;	
}