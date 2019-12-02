#include "median.h"
/*

- 3 median hivas + tomb kiiratasa 2x
	a, o
	b, paros
	c, paratlan

*/

double median(vector<double>& tomb) throw (domain_error)
{
    if(!tomb.size() || tomb.size() == 0){
            throw domain_error("Ures tomb!\n");
        }

    int n = tomb.size();
    if(tomb.size()%2 != 0){
        nth_element (tomb.begin(), tomb.begin()+(n/2), tomb.end());
        return tomb.at(n/2);
    }

    nth_element(tomb.begin(), tomb.begin()+((n/2) - 1), tomb.end());
    nth_element(tomb.begin(), tomb.begin()+((n/2) ), tomb.end());
    return (tomb.at(n/2) + tomb.at(n/2 - 1)) / 2;

}

void print(vector<double>& tomb)
{
    for(int i = 0; i < tomb.size(); i++)
    {
        cout<<tomb.at(i)<<"  ";
    }
    cout<<endl;
}
