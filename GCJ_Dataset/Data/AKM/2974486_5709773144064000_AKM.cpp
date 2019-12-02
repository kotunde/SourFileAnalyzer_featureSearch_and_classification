#include <iostream>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        long double c, f, x;
        cin >> c >> f >> x;
        long double ans = x / 2;
        long double build = 0;
        int farms = 0;
        while (build < ans)
        {
            ans = min(ans, build + x / (farms * f + 2));
            build += c / (farms * f + 2);
            farms++;
        }
        cout.precision(8);
        cout << "Case #" << tc << ": " << fixed << ans << endl;
    }
}
