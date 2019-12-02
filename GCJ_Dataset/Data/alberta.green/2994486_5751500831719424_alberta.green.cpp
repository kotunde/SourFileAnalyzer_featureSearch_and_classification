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
      int N;
      cin>>N;
	  vector<vector<pair<char, int> > > str;
      for (int i = 0; i < N; i++)
	  {
		  vector<pair<char, int> > temp;
		  char t;
		  cin>>t;
		  temp.push_back(pair<char,int>(t, 1));
		  while(cin.get(t) && t != '\n' && t != ' ')
		  {
			  if (t == temp[temp.size()-1].first)
				  temp[temp.size()-1].second++;
			  else
				  temp.push_back(pair<char,int>(t, 1));
		  }
		  str.push_back(temp);
	  }

	  int changes = 0;
	  for (int i = 0; i < str[0].size(); i++)
	  {
		  vector<int> num;
		  for (int j = 0; j < N; j++)
		  {
			  num.push_back(0);
			  if (str[j].size() != str[0].size())
			  {
				  changes = -1;
				  break;
			  }
			  else if (str[j][i].first != str[0][i].first)
			  {
				  changes = -1;
				  break;
			  }
			  else
			  {
				  for (int k = 0; k < N; k++)
				  {
					  num[j] += abs(str[k][i].second - str[j][i].second);
				  }
			  }
		  }
		  sort(num.begin(), num.end());

		  if (changes == -1)
			  break;
		  else
			  changes += num[0];
	  }

	  if (changes == -1)
		  cout<<"Fegla Won"<<endl;
	  else
		  cout<<changes<<endl;
    }
  return 0;
}