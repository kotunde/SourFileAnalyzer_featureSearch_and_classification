#include<iostream>
#include<algorithm>

using namespace std;

double a[1010], b[1010];

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, num = 0, t;
    cin>>t;    
    while(num < t) {
        ++num;
        cin>>n;
        for(int i = 0; i < n; ++i) cin>>a[i];
        for(int i = 0; i < n; ++i) cin>>b[i];
        sort(a, a + n);        
        sort(b, b + n);
        //score 2
        int l = 0, r = n-1, s2 = 0, s1 = 0;
        for(int i = n-1; i >= 0; --i) {
            if (b[r] > a[i]) --r;
            else ++l, ++s2;
        }        
        //score 1
        l = 0, r = n - 1;
        for(int i = 0; i < n; ++i) {
            if (a[i] < b[l]) --r;
            else ++l, ++s1;            
        }        
        printf("Case #%d: %d %d\n", num, s1, s2);
    }    
    return 0;
}
