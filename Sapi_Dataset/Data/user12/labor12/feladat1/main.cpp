#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int f=0;
    vector<string> words;
    string line;
    while( getline(cin, line) )
    {
        if( line.size() == 0 ) break;
        words.push_back(line);
    }
    int i;
    sort(words.begin(), words.end());
    do
    {
        ++f;
        cout << f << " ";
        for(i=0; i<words.size(); ++i)
        {
            cout << words[i] << " ";
        }
        cout << endl;
    }
    while(next_permutation(words.begin(), words.end()));

    return 0;
}
