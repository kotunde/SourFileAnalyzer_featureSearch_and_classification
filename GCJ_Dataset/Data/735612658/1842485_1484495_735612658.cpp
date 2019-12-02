
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 10086;
int mod;
int fact[100086];
void init ()
{
    int i;
    fact[0] = 1;
    for (i = 1; i <= mod; i ++)
    {
        fact[i] = (long long)fact[i - 1] * i % mod;
    }
}

int bspow (int a, int b)
{
    long long ans = 1;
    while (b)
    {
       if (b & 1)
       {
           ans = ans * a % mod;
       }
       a = (long long)a * a % mod;
       b /= 2;
    }
    return ans % mod;
}
int C (int n, int m)
{
    if (m > n)
        return 0;
    int res = 1;
    res = (long long)fact[n] * bspow ((long long)fact[n - m] * fact[m] % mod, mod - 2) % mod;
    return res;
}

int Lucas (int n, int m)
{
    int ans = 1;
    int a, b;
    while (n && m)
    {
        a = n % mod;
        b = m % mod;
        ans = ((long long) ans * C(a, b)) % mod;
        n /= mod;
        m /= mod;
    }
    return ans;
}

int main ()
{
    int t;
    scanf ("%d", &t);
    int n, m;
    while (t -- )
    {
        scanf ("%d%d%d", &n, &m, &mod);
        init ();
        int ans = Lucas (n + m, n);
        printf ("%d\n", ans);
    }
}
