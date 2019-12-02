#include<bits/stdc++.h>
using namespace std ;

const int MAXM = 8;
const int MAXN = 4;
const int MAXLEN = 10;

vector<vector<string> > servers;
string arr[MAXM+5];
int color[MAXM+5];
int m,n;
int maxi,ways;

int trie[85][26];

int trieSize(const vector<string>& vec){
    memset(trie,-1,sizeof(trie));
    int nn = 1;
    for (int c=0;c<vec.size();c++){
        int cur = 0;
        for (int c2=0;c2<vec[c].size();c2++){
            if (trie[cur][vec[c][c2] - 'A'] == -1)
                trie[cur][vec[c][c2] - 'A'] = nn++;
            cur = trie[cur][vec[c][c2] - 'A'];
        }
    }
    return nn;
}


void calcTries(){
    int mask = 0;
    for (int c=0;c<m;c++)
        mask |= (1 << color[c]);
    if (mask != ((1<<n) - 1))return ;
    servers.clear();
    servers.resize(n);
    for (int c=0;c<m;c++)
        servers[color[c]].push_back(arr[c]);
    int ret = 0;
    for (int c=0;c<n;c++)
        ret += trieSize(servers[c]);
    if (ret > maxi){
        maxi = ret;
        ways = 0;
    }
    if (ret == maxi)
        ways++;
    return ;
}

void brute(int i){
    if (i == m){
        calcTries();
        return ;
    }
    for (int c=0;c<n;c++){
        color[i] = c;
        brute(i + 1);
    }
    return ;
}

int main(){
    freopen("sharding.in","r",stdin);
    freopen("sharding.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    int test = 1;
    while (tests--){
        scanf("%d%d",&m,&n);
        for (c=0;c<m;c++){
            char word[MAXLEN+5];
            scanf("%s",word);
            arr[c] = word;
        }
        maxi = -1;
        ways = 0;
        memset(color,-1,sizeof(color));
        brute(0);
        printf("Case #%d: %d %d\n",test++,maxi,ways);
    }
    
    
    return 0;
}
