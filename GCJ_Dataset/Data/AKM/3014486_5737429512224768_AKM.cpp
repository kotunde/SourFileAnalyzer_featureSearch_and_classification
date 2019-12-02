#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        cout << "Case #" << tc << ": ";
        int n, x;
        cin >> n >> x;
        s.clear();
        for (int i = 0; i < n; i++)
        {
            int q;
            cin >> q;
            s.push_back(q);
        }
        sort(s.begin(), s.end());
        int e = n - 1, f = 0, ans = 0;
        while (f <= e)
        {
            if (e == f)
            {
                ans++;
                e--, f++;
                continue;
            }
            if  (s[e] + s[f] <= x)
                f++, e--;
            else
                e--;
            ans++;
        }
        cout << ans << endl;
    }
}
