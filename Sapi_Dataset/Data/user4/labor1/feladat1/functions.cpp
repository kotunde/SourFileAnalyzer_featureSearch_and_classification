#include"functions.h"
#include <iostream>
#include <cmath>

int countBits(int number)
{
    int nr=0;
    while(number)
    {
        if(number&1==1)
        {
            nr++;
        }
        number = number >> 1;
    }
    return nr;
}

int setBit(int& number, int order)
{
    if(order<0 || order>31)
    {
        return 0;
    }
    number = number | (1 << order);
    return 1;
}

double mean(double* array, int numElements)
{
    double aux = 0;
    for(int i = 0; i < numElements; i++)
    {
        aux += array[i];
    }
    aux /= numElements;
    return aux;
}

double stddev(double* array, int numElements)
{
    double n = 0, m = mean(array,numElements);
    for(int i = 0; i < numElements; i++)
    {
        n += (array[i] - m) * (array[i] - m);
    }
    n /= numElements;
    return sqrt(n);
}

double * max2(double* array, int numElements)
{
    double max[] = {0,0};
    if (numElements == 0)
    {
        return max;
    }
    if (numElements == 1)
    {
        max[0] = max[1] = array[0];
        return max;
    }
    max[1] = array[0];
    for (int i = 1; i < numElements; ++i)
    {
        if (array[i] >= max[1])
        {
            max[0] = max[1];
            max[1] = array[i];
        }
        else if (array[i] >= max[0])
        {
            max[0] = array[i];
        }
    }
    return max;
}

std::string capitalizeWords(std::string text)
{
    int i=1;
    std::string k;
    if ((int(text[0])>=97)&&(int(text[0])<=122))
    {
        text[0]=text[0]-32;
    }

    while (text[i])
    {
        if ((int(text[i])>=65)&&(int(text[i])<=90))
        {
            text[i]=text[i]+32;
        }
        if(text[i-1]==' ')
        {
            if ((int(text[i])>=97)&&(int(text[i])<=122))
            {
                text[i]=text[i]-32;
            }
        }
        i=i+1;

    }
    return text;
}

std::string code(std::string text)
{
    int i=0;
    while (text[i])
    {
        if ((int(text[i])>=97)&&(int(text[i])<122))
        {
            if (int(text[i])==122)
            {
                text[i]='a';
            }
            else
                text[i]=text[i]+1;
        }

        if ((int(text[i])>=65)&&(int(text[i])<90))
        {
            if (int(text[i])==90)
            {
                text[i]='A';
            }
            else
                text[i]=text[i]+1;
        }

        i=i+1;

    }
    return text;
}

int splitText(std::string chara)
{
   std::string word = "";
   for (auto x : chara)
   {
       if ((x == ' ')||(x == ',')||(x == '  ')||(x == '.')||(x == '?')||(x == '!'))
       {
           std::cout << word << std::endl;
           word = "";
       }
       else
       {
           word = word + x;
       }
   }
   std::cout << word << std::endl;
    return 0;

}
