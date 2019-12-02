
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        
    	int R = 0;
    	cin>>R;
        int C = 0;
    	cin>>C;
        int M = 0;
        cin>>M;
        
        if (M==R*C-1) {
            cout<<"Case #"<<tc+1<<": "<<endl;
            for (int ir=0; ir<R; ir++) {
                
                for (int ic=0; ic<C; ic++) {
                    if (ir==(R-1)&&ic==(C-1)) {
                        cout<<"c";
                    }
                    else
                    {
                        cout<<"*";
                        M--;
                    }

                }
                cout<<endl;
            }

        }
        else if ( R==1 || C==1) {
            if (R*C-M<2) {
                cout<<"Case #"<<tc+1<<": "<<endl<<"Impossible"<<endl;
            }
            else
            {
                cout<<"Case #"<<tc+1<<": "<<endl;
                for (int ir=0; ir<R; ir++) {
                    for (int ic=0; ic<C; ic++) {
                        if (ir==(R-1)&&ic==(C-1)) {
                            cout<<"c";
                        }
                        else if(M>0)
                        {
                            cout<<"*";
                            M--;
                        }
                        else {
                            cout<<".";
                        }
                    }
                    cout<<endl;
                }
            }
        }
        else if (M>R*C-4) {
            cout<<"Case #"<<tc+1<<": "<<endl<<"Impossible"<<endl;
        }
        else
        {
            cout<<"Case #"<<tc+1<<": "<<endl;
            for (int ir=0; ir<R; ir++) {
                for (int ic=0; ic<C; ic++) {
                    if (ir==(R-1)&&ic==(C-1)) {
                        cout<<"c";
                    }
                    else if(M>0&&!((R-ir<3)&&(C-ic<3)))
                    {
                        cout<<"*";
                        M--;
                    }
                    else {
                        cout<<".";
                    }
                }
                cout<<endl;
            }
        }
        
    }

    return 0;
}

