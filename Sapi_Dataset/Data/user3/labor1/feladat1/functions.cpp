#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

#include "functions.h"

int countBits(int number){
    int s=0;
    for(int i=0;i<sizeof(number)*8;i++){
        if(number & 1 == 1)
            s++;
        number=number>>1;
    }
    return s;
}

int setBit(int& number, int order){
    int x=1;
    x<<=order;

    if(order >= 0 && order <32){
        number=number|x;
        return 1;
    }

        return 0;

}

double mean(double array[], int numElements){
    if(numElements==0)
        return NULL;

    int s=0;
    for(int i=0; i<numElements;i++)
        s+=array[i];
    return (double)s/numElements;
}

double stddev(double array[], int numElements){
    if(numElements==0)
        return NULL;
    double m=mean(array, numElements);
    double s=0;
    for(int i=0; i<numElements; i++){
        s+=(array[i]-m)*(array[i]-m);
    }
    return (double)sqrt(s/numElements);
}

double* max2(double array[], int numElements){
    double* t=new double[2];
    if(numElements==0){
        t[0]=NULL;
        t[1]=NULL;
        return t;
    }
    if(numElements==1){
        t[0]=array[0];
        t[1]=array[0];
        return t;
    }
    if(array[0]>=array[1]){
        t[1]=array[0];
        t[0]=array[1];
    }
    else{
        t[0]=array[0];
        t[1]=array[1];
    }

    for(int i=2; i<numElements; i++){
        if(array[i]>t[0]){
            if(array[i]>t[1]){
                t[0]=t[1];
                t[1]=array[i];
            }
            else{
                t[0]=array[i];
            }
        }
    }
    return t;
}

string capitalizeWords(string text){
    int n=text.length();
    if(n==0)
        return NULL;
    text[0]=toupper(text[0]);
    for(int i=1; i<n; i++){
        if(text[i-1]==' '){
            if(text[i]>='a' && text[i]<='z'){
                text[i]=toupper(text[i]);
            }
        }
        else{
            if(text[i]>='A' && text[i]<='Z'){
                text[i]=tolower(text[i]);
            }
        }
    }
    return text;
}

string code(string text){
    int n=text.length();
    if(n==0)
        return NULL;

    for(int i=0; i<n; i++){
        if(text[i]>='a' && text[i]<'z'){
            text[i]=char(int(text[i])+1);
            continue;
        }
        if(text[i]=='z'){
            text[i]='a';
            continue;
        }
        if(text[i]>='A' && text[i]<'Z'){
            text[i]=char(int(text[i])+1);
            continue;
        }
        if(text[i]=='Z'){
            text[i]='A';
            continue;
        }
    }
    return text;
}

string decode(string text){
    int n=text.length();
    if(n==0)
        return NULL;

    for(int i=0; i<n; i++){
        if(text[i]>'a' && text[i]<='z'){
            text[i]=char(int(text[i])-1);
            continue;
        }
        if(text[i]=='a'){
            text[i]='z';
            continue;
        }
        if(text[i]>'A' && text[i]<='Z'){
            text[i]=char(int(text[i])-1);
            continue;
        }
        if(text[i]=='A'){
            text[i]='Z';
            continue;
        }
    }
    return text;
}

int splitText(string text){
    int n=text.length();
    if(n==0)
        return 0;

    int s=0,kezdo=0,vegso;
    for(int i=0; i<n; i++){
        char c=text[i];
        if(c==' ' || c==',' || c=='\t' || c=='?' || c=='!' || c=='.'){
            vegso=i;
            if(kezdo==vegso){
                kezdo++;
                continue;
            }
            for(int j=kezdo; j<vegso; j++){
                cout<<text[j];
            }
            cout<<", ";
            kezdo=i+1;
            s++;
        }
    }
    cout<<endl;
    return s;
}

// trim from start
static inline string &ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}
// trim from end
static inline string &rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}
// trim from both ends
static inline string &trim(string &s) {
    return ltrim(rtrim(s));
}

vector <string> splitCSVLine(string text){
    vector<string> v;
    int pos=0;
    while( (pos=text.find(",")) != string::npos){
        string word=text.substr(0,pos);
        v.push_back(trim(word));
        text.erase(0,pos+1); //pos+1 = pos + delimiter.length()
    }
    return v;
}
