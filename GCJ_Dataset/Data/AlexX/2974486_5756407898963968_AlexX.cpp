#include<iostream>

using namespace std;

int n, m, t, l1, l2;
int a[16], b[16];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>t;
    int c = 0;
    while(c < t) {
        ++c;
        cin>>l1;
        for(int i = 0; i < 16; ++i) cin>>a[i];
        cin>>l2;
        for(int i = 0; i < 16; ++i) cin>>b[i];
        int count = 0, now = 0;
        for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j) 
            if (a[(l1-1)*4 + i] == b[(l2-1)*4 + j]){
                ++count;
                now = a[(l1-1)*4 + i];                
            }
        if (count == 1) {
            cout<<"Case #"<<c<<": "<<now<<endl;   
        }
        else if (count == 0) {
            cout<<"Case #"<<c<<": Volunteer cheated!"<<endl;
        }
        else {
            cout<<"Case #"<<c<<": Bad magician!"<<endl;
        }
    }    
    return 0;
}
