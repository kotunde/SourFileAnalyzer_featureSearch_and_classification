#include<iostream>

using namespace std;

int n, m, t, l1, l2;
int a[16], b[16];

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>t;
    int num = 0;    
    double c, f, x;
    while(num < t) {
        ++num;
        cin>>c>>f>>x;
        int n = 0;        
        double ans = x/2, buy;
        while(true){                        
            ++n;
            buy = 0;
            for(int i = 0; i < n; ++i)
                buy += c / (2 + i * f);
            if (buy > ans) break;
            buy += x / (2 + n * f);
            if (buy < ans) ans = buy;
        }
        printf("Case #%d: %.9lf\n", num, ans);        
    }    
    return 0;
}
