#include <iostream>

using namespace std;

int main()
{
  int T;
  int x = 0;
  cin>>T;
  while(++x&&(T-x+1))
    {
      int first[4];
      int second[4];
      int row;

      cin>>row;
      for (int i = 0; i < row; ++i)
	cin.ignore(99999999, '\n');
      for (int i = 0; i < 4; ++i)
	{
	  cin>>first[i];
	}
	cin.ignore(99999999, '\n');
      for (int i = row; i < 4; ++i)
	cin.ignore(99999999, '\n');

      cin>>row;
      for (int i = 0; i < row; ++i)
	cin.ignore(99999999, '\n');
      for (int i = 0; i < 4; ++i)
	{
	  cin>>second[i];
	}
	cin.ignore(99999999, '\n');
      for (int i = row; i < 4; ++i)
	cin.ignore(99999999, '\n');

      bool work = false;
      int card = 0;
      for (int i = 0; i < 4; ++i)
	{
	  for (int j = 0; j < 4; ++j)
	    {
	      if (first[i] == second[j])
		{
		  if (card == 0)
		    {
		      card = first[i];
		      work = true;
		    }
		  else 
		    {
		      work = false;
		    }
		}
	    }
	}

      if (work)
	cout<<"Case #"<<x<<": "<<card<<endl;
      else if (card != 0)
	cout<<"Case #"<<x<<": Bad magician!"<<endl;
      else
        cout <<"Case #"<<x<<": Volunteer cheated!"<<endl;
    }
  return 0;
}
