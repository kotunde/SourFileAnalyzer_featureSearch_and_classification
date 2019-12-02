#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int T;
  int x = 0;
  cin>>T;
  while (++x&&T-x+1)
    {
      double C, F, X;
      cin>>C>>F>>X;
      double rate = 2;
      double time = X/rate;
      int farm = 0;
      double farmtime = 0;
      while (true)
	{
	  farm++;
	  farmtime += C/rate;
	  rate += F;
	  double newtime = farmtime + X/rate;
	  if (newtime < time)
	      time = newtime;
	  else
	    break;
	}
      cout<<"Case #"<<x<<": "<<fixed<<setprecision(7)<<time<<endl;
    }
  return 0;
}
