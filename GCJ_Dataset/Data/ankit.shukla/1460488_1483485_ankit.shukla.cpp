#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
using namespace std;

    string str="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string out="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    
    map<char,char> mp;
    char ch[1000];
    void preprocess(){
        mp['q']='z';
        int l=str.size();
        for(int i=0;i<l;i++){
            if(str[i]!=' ')
                mp[str[i]]=out[i];
        }
        bool used1[26],used2[26];
        for(int i=0;i<26;i++) used1[i]=used2[i]=false;
        tr(mp,it) used1[it->first-97]=used2[it->second-97]=true;

        int cnt1=0,cnt2=0,a,b;
        for(int i=0;i<26;i++){
            if(!used1[i]){
                cnt1++;
                a=i;
            }
            if(!used2[i]){
                cnt2++;
                b=i;
            }
        }
        assert(cnt1<=1 && cnt2<=1);
        
        mp[(char)(a+97)]=(char)(b+97);
        //cout<<mp.size()<<endl;
        //tr(mp,it) cout<<it->first<<" "<<it->second<<endl;
    }
    
    int main(){
        preprocess();  
        freopen("A-small-attempt0.IN","r",stdin);
        freopen("A-small-attempt0.OUT","w",stdout);
        int T,l;
        string s;
        cin>>T;
        getline(cin,s);
        for(int I=1;I<=T;I++){

            getline(cin,s);
            int l=s.size();
            //ch=s.c_str();
            for(int i=0;i<l;i++){
                if(s[i]!=' ') s[i]=mp[s[i]];
            }
            //printf("Case #%d: %s\n",I,ch);
            cout<<"Case #"<<I<<": "<<s<<endl;
        }
        //system("pause");
        return 0;
    }

