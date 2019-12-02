//
//  File.cpp
//  
//
//  Created by Akitsukirei on 2014/04/02.
//
//



#include <cmath>
#include <cstdio>
#include <vector>
#include <List>

#include <iostream>
#include <algorithm>

#include <regex>

using namespace std;

#define size 4


int main()
{
    int numTestCase,D,N;
    cin>>numTestCase;
    int tmp[4];
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        int sol = 0;
        cin>>sol;
    	for (int i =0; i<size; i++) {
            for (int j=0; j<size; j++) {
                int in = 0;
                cin>>in;
                if (i==(sol-1)) {
                    tmp[j] = in;
                }
            }
        }
        
        cin>>sol;
        int flag = 0;
        int result = 0;
        for (int i =0; i<size; i++) {
            for (int j=0; j<size; j++) {
                int in = 0;
                cin>>in;
                if (i==(sol-1)) {
                    for (int k=0; k<size; k++) {
                        if (tmp[k]==in) {
                            flag++;
                            result = in;
                        }
                    }
                }
                
            }
        }
        
        
        cout<<"Case #"<<tc+1<<": ";
        
        if (flag==0) {
            cout<<"Volunteer cheated!"<<endl;
        }
        else if (flag==1) {
            cout<<result<<endl;
        }
        else
        {
            cout<<"Bad magician!"<<endl;
        }

    }


    return 0;
}

