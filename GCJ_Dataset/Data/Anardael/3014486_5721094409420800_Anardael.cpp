#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int b[1005];
int N;
int solve(int m)
{
  int count=0;

  bool OK=false;

  do
  {
    OK=false;
    for (int i=0;i<=m-1;i++)
      if (b[i]>b[i+1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i+1];
	b[i+1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
 
  do
  {
     OK=false;
    for (int i=N-1;i>m;i--)
      if (b[i]>b[i-1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i-1];
	b[i-1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
  do
  {
    OK=false;
    for (int i=0;i<=m-1;i++)
      if (b[i]>b[i+1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i+1];
	b[i+1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
    return count;
}

int solve1(int m)
{
  int count=0;

  bool OK=false;
  do
  {
     OK=false;
    for (int i=N-1;i>m;i--)
      if (b[i]>b[i-1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i-1];
	b[i-1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
  do
  {
    OK=false;
    for (int i=0;i<=m-1;i++)
      if (b[i]>b[i+1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i+1];
	b[i+1]=tmp;
	OK=true;
	break;
      }
  }while (OK); 
  do
  {
     OK=false;
    for (int i=N-1;i>m;i--)
      if (b[i]>b[i-1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i-1];
	b[i-1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
  do
  {
    OK=false;
    for (int i=0;i<=m-1;i++)
      if (b[i]>b[i+1])
      {
	count++;
	int tmp=b[i];
	b[i]=b[i+1];
	b[i+1]=tmp;
	OK=true;
	break;
      }
  }while (OK);
 
 

    return count;
}

int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
  int a[1005];
  for (int ti=1;ti<=T;ti++)
  {
    
    f>>N;
    
    for (int i=0;i<N;i++)
      f>>a[i];
    int min=1000000000;
    for (int m=0;m<N;m++)
    {
      for (int i=0;i<N;i++)
	b[i]=a[i];
      int t=solve(m);
      if (min>t) min=t;
      for (int i=0;i<N;i++)
	b[i]=a[i];
      t=solve1(m);
      if (min>t) min=t;
       
    }
    w<<"Case #"<<ti<<": "<<min<<endl;
    
  }
  return 0;
}