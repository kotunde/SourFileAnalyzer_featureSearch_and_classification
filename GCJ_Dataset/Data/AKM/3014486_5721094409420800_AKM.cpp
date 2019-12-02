#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tmp = 0;
int ans = 2000;
#define pii pair<int, int>
vector<pii> q;
bool b[5][100];
void BT(int x)
{
    if (x == q.size())
    {
        ans = min(ans, tmp);
        return;
    }
    for (int j = 0; j < x; j++)
        if (b[0][j] && q[j].second > q[x].second)
            tmp++;
        else if (b[1][j] && q[j].second < q[x].second)
            tmp++;
    b[0][x] = true;
    BT(x + 1);
    b[0][x] = false;
    for (int j = 0; j < x; j++)
        if (b[0][j] && q[j].second > q[x].second)
            tmp--;
        else if (b[1][j] && q[j].second < q[x].second)
            tmp--;
    for (int j = 0; j < x; j++)
        if (b[1][j] && q[j].second < q[x].second)
            tmp++;
        else if (b[0][j] && q[j].second > q[x].second)
            tmp++;
    b[1][x] = true;
    BT(x + 1);
    b[1][x] = false;
    for (int j = 0; j < x; j++)
        if (b[1][j] && q[j].second < q[x].second)
            tmp--;
        else if (b[0][j] && q[j].second > q[x].second)
            tmp--;
}
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        cout << "Case #" << tc << ": ";
        int n;
        cin >> n;
        q.clear();
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push_back(pii(a, i));
        }
        sort(q.begin(), q.end());
        ans = 2000;
        BT(0);
        cout << ans << endl;
    }
}
