#include<iostream>
using namespace std;
main()
{
   // freopen("in.txt",stdin);
    //freopen("out.txt",stdout);
    long t,p,q,s,i,f;
    double c;
    char ch;
    cin>>t;
    for(i=1;i<=t;i++)
    {f=0;
        cin>>p>>ch>>q;
        c=(double)p/(double)q;
        s=0;
        if(q%2)f=1;
        while(c<1)
          {
            s++;
            c=c*2;
          }
          if(f){cout<<"Case #"<<i<<": impossible"<<endl;}
 
            else{
      cout<<"Case #"<<i<<": "<<s<<endl;}
 
    }
return 0;
}