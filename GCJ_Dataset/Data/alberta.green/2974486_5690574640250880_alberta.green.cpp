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
      int R,C,M;
      cin>>R>>C>>M;

      cout<<"Case #"<<x<<":"<<endl;
      if (R*C-M == 1)
	{
	  for (int i = 0; i < R; ++i)
	    {
	      for (int j = 0; j < C; ++j)
		{
		  if (i == R-1 && j == C-1)
		    cout<<"c";
		  else
		    cout<<"*";
		}
	      cout<<endl;
	    }
	}
      else if (R == 1 || C == 1)
	{
	  for (int i = 0; i < R; ++i)
	    {
	      for (int j = 0; j < C; ++j)
		{
		  if (M)
		    {
		      cout<<"*";
		      --M;
		    }
		  else if (i == R-1 && j == C-1)
		    cout<<"c";
		  else cout<<".";
		}
	      cout<<endl;
	    }
	}

      else if (M == R*C-2 || M==R*C-3 || M==R*C-5 || M==R*C-7)
	cout<<"Impossible"<<endl;

      else if (R == 2)
	{
	  if (M % 2 == 0)
	    {
	      for (int i = 0; i < R; ++i)
		{
		  for (int j = 0; j < M/2; ++j)
		    {
		      cout<<"*";
		    }
		  for (int j = M/2; j < C; ++j)
		    {
		      if (i == R-1 && j == C-1)
			cout<<"c";
		      else
			cout<<".";
		    }
		  cout<<endl;
		}
	    }
	  else
	    {
	      cout<<"Impossible"<<endl;
	    }
	}

      else if (C == 2)
	{
	  if (M % 2 == 0)
	    {
	      for (int i = 0; i < R; ++i)
		{
		  for (int j = 0; j < C; ++j)
		    {
		      if (M)
			{
			  cout<<"*";
			  --M;
			}
		      else if (i == R-1 && j == C-1)
			cout<<"c";
		      else cout<<".";
		    }
		  cout<<endl;
		}
	    }
	  else
	    {
	      cout<<"Impossible"<<endl;
	    }
	}

      else if ((R*C-M) / C > 1)
	{
	  if ((R*C-M) % C != 1)
	    {
	      for (int i = 0; i < R; ++i)
		{
		  for (int j = 0; j < C; ++j)
		    {
		      if (M)
			{
			  cout<<"*";
			  --M;
			}
		      else if (i == R-1 && j == C-1)
			cout<<"c";
		      else cout<<".";
		    }
		  cout<<endl;
		}
	    }
	  else 
	    {
	      if ((R*C-M) / C == 2)
		{
		  for (int i = 0; i < R - ((R*C-M) / C) - 1; ++i)
		    {
		      for (int j = 0; j < C; ++j)
			{
			  cout<<"*";
			}
		      cout<<endl;
		    }
		  for (int j = 0; j < C-3; ++j)
		    {
		      cout<<"*";
		    }
		  cout<<"..."<<endl;
		  for (int i = 0; i < 2; ++i)
		    {
		      cout<<"*";
		      for (int j = 0; j < C-1; ++j)
			{
			  if (R - (M / C) == 3 && j == C-2 && i == 1)
			    cout<<"c";
			  else 
			    cout<<".";
			}
		      cout<<endl;
		    }
		}
	      else 
		{
		  for (int i = 0; i < R - ((R*C-M) / C) - 1; ++i)
		    {
		      for (int j = 0; j < C; ++j)
			{
			  cout<<"*";
			}
		      cout<<endl;
		    }
		  for (int j = 0; j < C-2; ++j)
		    {
		      cout<<"*";
		    }
		  cout<<".."<<endl;
		  cout<<"*";
		  for (int j = 0; j < C-1; ++j)
		    {
		      cout<<".";
		    }
		  cout<<endl;
		  for (int i = R - ((R*C-M) / C) + 1; i < R; ++i)
		    {
		      for (int j = 0; j < C; ++j)
			{
			  if (j == C-1 && i == R -1)
			    cout<<"c";
			  else
			    cout<<".";
			}
		      cout<<endl;
		    }
		}
	    }
	}
      else 
	{
	  if ((M-C*(R-2)) % 2 == 0)
	    {
	      for (int i = 0; i < R-2; ++i)
		{
		  for (int j = 0; j < C; ++j)
		    {
		      cout<<"*";
		      --M;
		    }
		  cout<<endl;
		}
	      for (int i = 0; i < 2; ++i)
		{
		  for (int j = 0; j < M/2; ++j)
		    {
		      cout<<"*";
		    }
		  for (int j = M/2; j < C; ++j)
		    {
		      if (i == 1 && j == C-1)
			cout<<"c";
		      else
			cout<<".";
		    }
		  cout<<endl;
		}
	    }
	  else 
	    {
	      for (int i = 0; i < R-3; ++i)
		{
		  for (int j = 0; j < C; ++j)
		    {
		      cout<<"*";
		      --M;
		    }
		  cout<<endl;
		}
	      for (int j = 0; j < C - 3; ++j)
		{
		  cout<<"*";
		  --M;
		}
	      cout<<"..."<<endl;
	      for (int i = 0; i < 2; ++i)
		{
		  for (int j = 0; j < M/2; ++j)
		    {
		      cout<<"*";
		    }
		  for (int j = M/2; j < C; ++j)
		    {
		      if (i == 1 && j == C-1)
			cout<<"c";
		      else
			cout<<".";
		    }
		  cout<<endl;
		}
	    }
	}
    }
  return 0;
}
