#include<bits/stdc++.h>
using namespace std ;

#define foreach(it,a) for(__typeof((a).begin())it=(a).begin();it!=(a).end();it++)

int main(){
    freopen("trick.in","r",stdin);
    freopen("trick.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        int a1,a2;
        set<int> s1,s2;
        scanf("%d",&a1);
        for (int c=1;c<=4;c++)
        for (int c2=1;c2<=4;c2++){
            int v;
            scanf("%d",&v);
            if (c == a1)
                s1.insert(v);
        }
        scanf("%d",&a2);
        for (int c=1;c<=4;c++)
        for (int c2=1;c2<=4;c2++){
            int v;
            scanf("%d",&v);
            if (c == a2)
                s2.insert(v);
        }
        set<int> ret;
        foreach (it,s1)
            if (s2.find(*it) != s2.end())
                ret.insert(*it);
        printf("Case #%d: ",test);
        if (ret.size() == 1)
            printf("%d\n",*ret.begin());
        else if (ret.size() == 0)
            printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
            
    
    
    return 0;
}
