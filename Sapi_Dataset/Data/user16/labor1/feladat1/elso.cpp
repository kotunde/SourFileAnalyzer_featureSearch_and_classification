#include "elso.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>


int countBits(int number)
{
    int db = 0;
    while (number)
    {
        if (number & 1)
            db++;
        number>>=1;
    }
    return db;
}

int setBit(int& number, int order)
{
    if (order>31 || order <0)
        return 0;
    number |= (1u << order);
    return 1;
}

double mean(double t[], int numElements)
{
    double avg = 0;
    if (!numElements)
        return NAN;
    for (int i = 0 ; i<numElements ; i++)
        avg+=t[i];
    return avg/numElements;
}

double stddev(double t[], int numElements)
{
    if (!numElements)
        return NAN;
    double dev = 0;
    double avg = mean(t,numElements);
    for (int i = 0 ; i<numElements; i++)
        dev = dev + (t[i] - avg)*(t[i] - avg);
    dev/=numElements;
    return sqrt(dev);

}


double * max2(double t[], int numElements)
{
    double * x = new double[2];
    if (!numElements)
    {
        x[0] = x[1] = NAN;
        return x;
    }

    else if (numElements == 1)
    {
        x[0] = x[1] = t[0];
        return x;

    }

    double elso = t[0], masodik =  t[0];
    for (int i = 1 ; i<numElements ; i++)
    {
        if (t[i]>elso)
        {
            masodik = elso;
            elso = t[i];
        }
    }
    x[0] = elso;
    x[1] = masodik;
    return x;
}

string capitalizeWords(string text)
{
    if (text[0]>='a' && text[0]<='z')
        text[0]-=32;

    for (int i = 1 ; i<text.length(); i++)
    {
        if (text[i-1]==' ' && text[i]>='a' && text[i]<='z')
        {
            text[i]-=32;
            continue;
        }
        if (text[i]>='A' && text[i]<='Z' && text[i-1]!=' ')
            text[i]+=32;
    }
    return text;
}

string code(string text)
{
    if (!isgood(text))
        return text;
    for (int i = 0 ; i<text.length(); i++)
    {
        if (text[i]==' ')
            continue;
        else if (text[i]=='z')
            text[i]='a';
        else if (text[i]=='Z')
            text[i]='A';
        else text[i]++;
    }
    return text;
}

bool isgood (string text)
{
    for (int i = 0 ; i<text.length(); i++)
        if (text[i]>='0' && text[i]<='9')
            return false;
    return true;
}

int splitText(string text)
{
    char t[] =" ,.!?";
    char s[100];
    strcpy(s,text.c_str());
    char * p = strtok(s,t);
    int db = 0;
    while (p)
    {
        cout<<p<<endl;
        p = strtok(NULL,t);
        db++;
    }
    return db;
}

vector<string> splitCSVLine(string text)
{
    int start = 0;
    vector<string> szavak;
    std::size_t st;
    std::size_t poz = text.find(',');
    while (poz!=string::npos)
    {
        for (int i = start ; i<text.length(); i++)
            if (text[i] == ' ')
            {
                text.erase(i,poz-i);
                break;
            }
        //cout<<text<<endl;
        st = text.find(',');
        int j = st+1;
        while (text[j]==' ')
            j++;
        text[st]='*';
        text.erase(st+1,j-st-1);
        //cout<<text<<endl;
        poz = text.find(',');
    }
    char s[100];
    strcpy(s,text.c_str());
    char * p = strtok (s,"*");
    while (p)
    {
        szavak.push_back(p);
        p = strtok(NULL,"*");
    }
    return szavak;
}
