#include<bits/stdc++.h>
using namespace std ;

multiset<int> sizes;
int n,cap;

int getBest(int threshold){
    if (sizes.size() == 0)return -1;
    multiset<int> :: iterator it = sizes.upper_bound(threshold);
    if (it == sizes.begin())return -1;
    int ret = *--it;
    sizes.erase(it);
    return ret;
}


int main(){
    freopen("small.in","r",stdin);
    freopen("packing.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    int test = 1;
    while (tests--){
        sizes.clear();
        scanf("%d%d",&n,&cap);
        for (c=0;c<n;c++){
            int sz;
            scanf("%d",&sz);
            sizes.insert(sz);
        }
        int ret = 0;
        while (!sizes.empty()){
            int cur = *sizes.begin();
            sizes.erase(sizes.begin());
            int threshold = cap - cur;
            getBest(threshold);
            ret++;
        }
        printf("Case #%d: %d\n",test++,ret);
    }
    
    
    return 0;
}
