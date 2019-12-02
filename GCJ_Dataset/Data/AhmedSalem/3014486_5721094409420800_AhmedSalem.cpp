#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 1000;
const int oops = 1e9;

#define foreach(it,a) for(__typeof((a).begin()) it = (a).begin() ; it != (a).end(); it ++)

pair<int,int> vals[MAXN+5];
#define value first
#define ix second

int bit[MAXN+5];


map<int,int> rank;
int arr[MAXN+5];
int withoutMax[MAXN+5];

int n;

int temp[MAXN+5];


int query(int i){
    if (i < 0)return 0;
    int ret = 0;
    for (i++;i>0;i-=i&-i)
        ret += bit[i];
    return ret;
}
int query(int s,int e){
    if (s > e)return 0;
    return query(e) - query(s-1);
}
void update(int i,int val){
    for (i ++; i <= n; i+= i&-i)
        bit[i] += val;
    return ;
}



int main(){
    freopen("updown.in","r",stdin);
    freopen("updown.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        scanf("%d",&n);
        rank.clear();
        int i = 0;
        for (c=0;c<n;c++){
            scanf("%d",&arr[c]);
            rank[arr[c]];
            vals[c].value = arr[c];
            vals[c].ix = c;
        }
        int cnt = 0;
        foreach(it,rank)
            it->second = cnt++;
        sort(vals,vals+n);
        memset(bit,0,sizeof(bit));
        for (c=0;c<n;c++)
            update(c,1);
        int ret = 0;
        for (c=0;c<n;c++){
            i = vals[c].ix;
            ret += min(query(i-1),query(i+1,n-1));
            update(i,-1);
        }
        printf("Case #%d: %d\n",test,ret);
        //printf("%d\n",ret);
    }
    
    
    return 0;
}
