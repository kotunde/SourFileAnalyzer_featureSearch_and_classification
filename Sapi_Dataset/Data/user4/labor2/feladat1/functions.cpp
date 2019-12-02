#include"functions.h"
#include <math.h>

bool negyzet(Pont a, Pont b, Pont c, Pont d)
{
    if(hasonlit(a,b) && hasonlit(b,c) && hasonlit(c,d) && hasonlit(d,a))
    {
        return false;
    }
    if((tavolsag(a,b)==tavolsag(b,c)==tavolsag(c,d)==tavolsag(d,a)) && (tavolsag(a,c)==tavolsag(b,d)))
    {
        return true;
    }
    return false;
}

double tavolsag(Pont a, Pont b)
{
    return sqrt((a.getX()-b.getX()) * (a.getX()-b.getX()) + (a.getY()-b.getY()) * (a.getY()-b.getY()));
}

bool hasonlit(Pont a, Pont b)
{
    if((a.getX() == b.getX()) && (a.getY() == b.getY()))
        return true;
    return false;
}

double* legkissebblegnagyobbTav(Pont*a,int n){
    double mini = 10000000;
    double maxi = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){

                double x=tavolsag(a[i],a[j]);
                if(x < mini){
                    mini = x;
                }
                if(x > maxi){
                    maxi = x;
                }

        }
    }
    double * aux = new double[ 2 ] {mini,maxi};
    return aux;
}

bool rendezesHasonlito(Pont A, Pont B) {

	return (A.getX()<B.getX());
}
