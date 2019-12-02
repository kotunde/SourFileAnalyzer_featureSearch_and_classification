//
// Created by Tundi on 9/29/2018.
//

#include <iostream>
#include <fstream>
#include "stringffv.h"
//csak egy helyen kell legyen beincludeolva
//#include <string>
//using namespace std;


string capitalizeWords(string text)
{

    int n,i;
    for (i=0; i<text.length(); ++i)
    {
        if ((i==0 || text[i-1]==' ') && (islower(text[i])))
        {
            text[i]=_toupper(text[i]);
        }
        else if (text[i]!=' ' && text[i-1]!= ' ' && isupper(text[i]))
        {
            text[i]=_tolower(text[i]);
        }
    }
    return text;
}
string code(string text)
{
    int i;
    for (i=0; i<text.length(); ++i)
    {
        if ((text[i] >=65 && text[i]<90) || (text[i]>=97 && text[i]<122))
        {
            text[i]=(char)((int)text[i]+1);
        }
        else if (text[i]==(char)90)
        {
            text[i]=(char)65;
        }
        else if (text[i]==(char)122)
        {
            text[i]=(char)97;
        }
    }
    return text;
}
string decode(string text)
{
    int i;
    for (i=0; i<text.length(); ++i)
    {
        if ((text[i] >65 && text[i]<=90) || (text[i]>97 && text[i]<=122))
        {
            text[i]=(char)((int)text[i]-1);
        }
        else if (text[i]==(char)65)
        {
            text[i]=(char)90;
        }
        else if (text[i]==(char)97)
        {
            text[i]=(char)122;
        }
    }
    return text;
}
int splitText(string text)
{
    int i=0;
    int nr=0;
    //cout << text.length() << endl;
    while (i<text.length())
    {
        while(i < text.length() && text[i] != (char)33 && text[i] != (char)32 && text[i] != (char)9 && text[i] != (char)44 && text[i] != (char)46 && text[i] != (char)63)
        {
            cout << text[i];
            //cout << i;
            ++i;
        }
        cout << endl;
        ++nr;
        ++i;
    }
    return nr;
}

vector<string> splitCSVLine(string text)
{
    vector<string> words;

    std::ifstream file("input.csv");
    string line;

    while(getline(file,line))
    {
        string buff;
        //ameddig nem kap vesszot addig masol a temp-be majd azt beteszi a vektorba
        int i=0;
        while(line[i]!=(char)44)
        {
            buff+=line[i];
        }
        words.push_back(buff);
    }
    return words;
}