#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <utility>  // for pair
using namespace std;
typedef long long ll;
inline int min(int a, int b){return a < b? a: b;}
inline int max(int a, int b){return a > b? a: b;}

const int dis =  450000;
const int size = 2100;

int high[size], data[size];
int n;

bool fun()
{
    for(int i = 1; i < n - 1; i++)
        for(int j = i + 1; j < data[i]; j++)
            if(data[j] > data[i])
                return true;
    return false;
}
void getans()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = data[i] - 1; j > i; j --)
            high[j] -= (data[i] - j);
    }
}
int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas; cin >> cas;
    for(int cc = 1; cc <= cas; cc ++)
    {
        cin >> n;
        for(int i = 1; i < n; i++)
            cin >> data[i];
        for(int i = 1; i <= n ;i++)
            high[i] = i * dis;

            cout << "Case #" << cc << ":";
        if( fun() )
        {
            cout << " Impossible" << endl;
            continue;
        }

        getans();

        for(int i = 1; i <= n ;i++)
            cout << " " << high[i];
        cout << endl;

    }
    return 0;
}
