#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "D.in"
#define FILEOUT "D.out"

int N;
int M;
string s[15];

vector<int> build_mask(int num){
    
    vector<int> res;
    for(int i = 0; i < M; ++i){
        res.pb(num%N);
        num/=N;
    }
    return res;
}

vector<int> trie[1000];
vector<char>  sym;

int solve(const vector<string>& ss){
    int cnt = 0;
    sym.clear();
    sym.assign(1, ' ');
    trie[0].clear();
    for(int i = 0; i < ss.size(); ++i){
        int curcnt = 0;
        for(int j = 0; j <ss[i].size(); ++j){
            bool found = false;
            for(int k = 0; k < trie[curcnt].size(); ++k){
                if(sym[trie[curcnt][k]] == ss[i][j]){
                    found = true;
                    curcnt = trie[curcnt][k];
                    break;  
                }
            }
            if(!found){
                cnt++;
                sym.push_back(ss[i][j]);
                trie[cnt].clear();
                trie[curcnt].push_back(cnt);
                curcnt = cnt;
            }
        }
    }

    return cnt + 1;
}

int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	cin>>M>>N;
    	for(int i = 0; i < M; ++i)
    		cin>>s[i];
        int maxres = 0;
        int cnt = 0;
    	for(int i = 0; i < int(pow(N,M) + 0.1); ++i){
            //cout<<i<<"\n";
            vector<int> mask = build_mask(i);
            vector<vector<string> > curmasks(N);
            for(int j = 0; j < M; ++j){
                curmasks[mask[j]].push_back(s[j]);
            }
            int curres =0;
            bool isempty = false;
            for(int j = 0; j < N; ++j){
                if(curmasks[j].empty()){
                    isempty = true;
                    break;
                }
                //curres += solve(curmasks[j]);
            }
            if(!isempty){
                for(int j = 0; j < N; ++j)
                    curres += solve(curmasks[j]);
                if(curres > maxres){
                    maxres = curres;
                    cnt = 1;
                }
                else if(curres == maxres){
                    ++cnt;
                }
            }
    	}
        

        cout << "Case #" << _ << ": ";
        cout<<maxres<<" "<<cnt<<endl;
    }
    return 0;
}