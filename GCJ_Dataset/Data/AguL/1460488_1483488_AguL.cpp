#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int __, l, r, ans, cur, last, ll, qq;
    scanf("%d", &__);
    for (int _ = 1; _ <= __; _++) {
        scanf("%d %d", &l, &r);
        cur = l;
        ll = 1;
        qq = -1;
        while (cur > 0) {
            ll *= 10;
            cur /= 10;
            qq++;
        }
        ll /= 10;
        ans = 0;
        for (int i = l; i <= r; i++) {
            cur = i;
            for (int j = 0; j < qq; j++) {
                last = cur % 10;
                cur = cur / 10 + last * ll;
                ans += (cur > i && cur <= r && last != 0);
            }
        }
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}
