#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const string lang = "yhesocvxduiglbkrztnwjpfmaq";

string s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int __;
    scanf("%d\n", &__);
    for (int _ = 1; _ <= __; _++) {
        getline(cin, s);
        int ls = s.length();
        for (int i = 0; i < ls; i++)
            if (s[i] != ' ') s[i] = lang[s[i] - 97];
        printf("Case #%d: %s\n", _, s.c_str());
    }
    return 0;
}
