#include <cmath>
#include <string>
#include <cstring>
#include "lab1.h"
#include <iostream>
using namespace std;
int countBits(int number)
{
    int s=0;
    while(number)
    {
        s=s+(number&1);
        number=number>>1;
    }
    return s;
}
int setBit(int& number, int order)
{
    if (order>31||order<0)
    {
        return 0;
    }
    else
    {
        number|= 1UL<<order;
        return 1;
    }

}
double mean(double a[], int numElements)
{
    if(numElements==0)
    {
        return NAN;
    }
    int i;
    double osz=0;
    for(i=0; i<numElements; ++i)
    {
        osz+=a[i];
    }
    return osz/numElements;
}
double stddev(double a[], int numElements)
{
    if(numElements==0)
    {
        return NAN;
    }
    double atl= mean(a,numElements);
    int i;
    double szum=0;
    for(i=0; i<numElements; ++i)
    {
        double s=0;
        s=a[i]-atl;
        szum+=s*s;
    }
    return sqrt(szum/numElements);
}
double * max2(double a [], int numElements )
{
    double *maxi=new double[2]{NAN,NAN};
    if(numElements==0)
    {
        return maxi;
    }
    else if(numElements==1)
    {
        maxi[0]=a[0];
        maxi[1]=a[0];
        return maxi;
    }
    int i;
    maxi[0]=a[0];
    maxi[1]=a[1];
    if(maxi[0]>maxi[1]){
        double v=maxi[0];
        maxi[0]=maxi[1];
        maxi[1]=v;
    }
    for(i=2; i<numElements; ++i)
    {
        if(maxi[1]<a[i])
        {
            maxi[0]=maxi[1];
            maxi[1]=a[i];
        }
        if(a[i]>maxi[0]&&a[i]<maxi[1])
        {
            maxi[0]=a[i];
        }

    }
    return maxi;
}
string capitalizeWords(string text)
{
    text[0]=toupper(text[0]);
    int i;
    for(i=1; i<text.length(); ++i)
    {
        if(text[i-1]==' ')
        {
            text[i]=toupper(text[i]);
        }
        else
        {
            text[i]=tolower(text[i]);
        }

    }
     return text;
}
string code(string text)
{
    int s,i;
    for(i=0; i<text.length(); ++i)
    {
        s=(int)text[i];
        if(s>=65&&s<=90)
        {
            if(s==90)
            {
                s=65;
            }
            else
            {
                ++s;
            }
        }
        if(s>=97&&s<=122)
        {
            if(s==122)
            {
                s=97;
            }
            else
            {
                ++s;
            }
        }
        text[i]=(char)s;
    }
    return text;
}
string decode(string text )
{
    int s=0,i;
    for(i=0; i<=text.length(); ++i)
    {
        s=(int)text[i];
        if(s>=65&&s<=90)
        {
            if(s==65)
            {
                s=90;
            }
            else
            {
                --s;
            }
        }
        if(s>=97&&s<=122)
        {
            if(s==97)
            {
                s=122;
            }
            else
            {
                --s;
            }
        }
        text[i]=(char)s;
    }
    return text;
}
int splitText(string text)
{
    int szum=0,i;
    cout<<"szavak: " <<endl;
    for(i=0; i<=text.length(); ++i)
    {
        cout<<text[i];
        if(text[i]==' '||text[i]=='!'||text[i]=='.'||text[i]=='?'||text[i]==','||text[i]=='\t'||text[i]=='\0')
        {

            szum++;
            cout<<endl;
        }

    }
    return szum;

}
/*vector<string> splitCSVLine(string text){

}
static inline std::string &trim(std::string &s) {
 return ltrim(rtrim(s));
}
*/
