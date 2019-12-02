#include <iostream>
#include <vector>

using namespace std;

int bst;
int tmp = 0, vcnt = 10, cnt = 0;
#define pii pair<int, int>
int use[10000000];
string s[20];
vector<pii> childs[10000000];
int n, m;
void add(int t, int v, int q, int x)
{
    use[v]++;
    if (use[v] == 1)
        tmp++;
    if (x == s[q].size())
        return;
    bool ok = false;
    for (int i = 0; i < childs[v].size(); i++)
        if (childs[v][i].first == s[q][x])
        {
            ok = true;
            add(t, childs[v][i].second, q, x + 1);
        }
    if (!ok)
    {
        childs[v].push_back(pii(s[q][x], vcnt++));
        add(t, vcnt - 1, q, x + 1);
    }
}
void del(int t, int v, int q, int x)
{
    use[v]--;
    if (use[v] == 0)
        tmp--;
    for (int i = 0; i < childs[v].size(); i++)
        if (childs[v][i].first == s[q][x])
            del(t, childs[v][i].second, q, x + 1);
}
void BT(int x)
{
    if (x == n)
    {
        if (tmp > bst)
        {
            bst = tmp;
            cnt = 1;
        }
        else if (tmp == bst)
            cnt++;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        add(i, i, x, 0);
        BT(x + 1);
        del(i, i, x, 0);
    }
}
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        cout << "Case #" << tc << ": ";
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        bst = 0;
        BT(0);
        cout << bst << " " << cnt << endl;
        /*add(0, 0, 0, 0);
        cout << tmp << endl;*/
    }
}
