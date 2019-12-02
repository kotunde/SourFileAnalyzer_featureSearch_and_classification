#include <iostream>

int countBits(int n){
   int a=0, x=n;
while(x>0){
   if(x%2==1){++a;}
    x/=2;
}
return a;
}

double mean(double a[], int n){
int i,f=0;
for(i=0; i<n; ++i){
    f=f+a[i];
}
if(f==0){return 0;}
f=f/(n+1);
return f;
}

int setBit(int n, int order){
n|=1<<order;
return order<32;
}

double* max2(double a[], int n){
int i, max1=0, max2=0, j, max3, index,c;
double* s=new double[2];
if(n==1){s[0]=s[1]=a[0];
return s;}
for (i=0;i<n;i++){
        max3=a[i];
        for (j=i+1;j<n;j++)
            if (max3>a[j])
            {
                max3=a[j];
                index=j;
            }
        c=a[i];
        a[i]=max3;
        a[index]=c;
    }
    max1=a[n-1]; max2=a[n-2];
if(max1>max2){s[0]=max2; s[1]=max1;}
else{s[0]=max1; s[1]=max2;}
return s;
}

