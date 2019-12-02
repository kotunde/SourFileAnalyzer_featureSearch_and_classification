#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<long double> st;
long double b[1010], a[1010];
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        st.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            st.insert(b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int e = 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            set<long double>::iterator it = st.lower_bound(a[i]);
            if (it == st.end())
                sum1++;
            else
                st.erase(it);
        }
        for (int i = 0; i < n; i++)
            if (a[i] < b[e])
                continue;
            else
            {
                sum2++;
                e++;
            }

        cout << "Case #" << tc << ": " << sum2 << " " << sum1 << endl;
    }
}
