//
// Created by tuni on 10/13/18.
//

#include <iostream>
#include "Pont.h"
#include <cmath>
#include <algorithm>
#define N 1000000

Pont::Pont(int x, int y)
{
    if (x >= 0 && x <= 2000) this->x = x;
    else
        this->x = 0;
    if (y >= 0 && y <= 2000) this->y = y;
    else
        this->y = 0;
}
int Pont::getX() const
{
    return x;
}
int Pont::getY() const
{
    return y;
}
void Pont::setX(int x)
{
    if (x >= 0 && x <= 2000) this->x = x;
}
void Pont::setY(int y)
{
    if (y >= 0 && y <= 2000) this->y = y;
}
void Pont::move(int nx, int ny)
{
    if (nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000)
    {
        this->x = nx;
        this->y = ny;
    }
}

const static int a[16]={-1,0,1,0,-1,-1,1,1,-2,0,2,0,-2,-2,2,2};
const static int b[16]={0,1,0,-1,-1,1,1,-1,0,2,0,-2,-2,2,2,-2};


bool my_cmp(const Pont&, const Pont&);



///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double findmin(bool ** table, int n)
{
    // indexek inicializalasa
    int i = 0, j = 0 ,f;
    double d = 1000, min=4;
    Pont p1,p2;

    //irany inicializalasa
    bool isUp = true;

    // atlos belyaras amig minden elem sorra kerul
    for (int k=0; k<n*n;)
    {
        // ha az IsUp igaz akkor lentrol felfele megyunk
        if (isUp)
        {
            for ( ; i>=0 && j<n ; j++, i--)
            {
                ///megnezzuk a szomszedokat
                if (table[i+2][j+2])
                {
                    for (f=0; f<16; ++f)
                    {
                        if (table[i+a[f]+2][j+b[f]+2])
                        {
                            d=distance(i,j,i+a[f],j+b[f]);
                            if (d < min)
                            {
                                min=d;
                                p1.setX(i); p1.setY(j);
                                p2.setX(i+a[f]); p2.setY(j+b[f]);
                            }
                            if (d==1)
                            {
                                k=n*n;
                            }
                        }
                    }
                }
                k++;
            }

            // az i es j beallitasa az iranynak megfeleloen
            if (i < 0 && j<=n-1)
                i = 0;
            if (j == n)
                i = i+2 , j--;
        }

            // ha az isUp = 0 akkor fentrol lefele
        else
        {
            for ( ; j >= 0 && i<n ; i++ , j--)
            {
                if (table[i+2][j+2])
                {
                    for (f=0; f<16; ++f)
                    {
                        if (table[i+a[f]+2][j+b[f]+2])
                        {
                            d=distance(i,j,i+a[f],j+b[f]);
                            if (d < min)
                            {
                                min=d;
                                p1.setX(i); p1.setY(j);
                                p1.setX(i+a[f]); p2.setY(j+b[f]);
                            }
                            if (d==1)
                            {
                                k=n*n;
                            }
                        }
                    }
                }
                k++;
            }

            // az i es j beallitasa az iranynak megfeleloen
            if (j < 0 && i<=n-1)
                j = 0;
            if (i == n)
                j = j + 2 , i--;
        }

        // iranyvaltas
        isUp = !isUp;
    }
    cout << endl <<"(" << p1.getX() << "," << p1.getY() << ")"<< "&" << "(" << p2.getX() << "," << p2.getY() << ")" << endl;
    return d;
}



///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double findmax(bool **table, int n)
{
    Pont a,b;
    //FENTROL

    int i = 0, j = 0 ;

    bool isUp = true;

    for (int k=0; k<n*n;)
    {
        if (isUp)
        {
            for ( ; i>=0 && j<n ; j++, i--)
            {
                if (table[i+2][j+2])
                {
                    a.setX(i);
                    a.setY(j);
                    k=n*n;
                }
                k++;
            }

            if (i < 0 && j<=n-1)
                i = 0;
            if (j == n)
                i = i+2 , j--;
        }

        else
        {
            for ( ; j >= 0 && i<n ; i++ , j--)
            {
                if (table[i+2][j+2])
                {
                    a.setX(i);
                    a.setY(j);
                    k=n*n;
                }
                k++;
            }

            if (j < 0 && i<=n-1)
                j = 0;
            if (i == n)
                j = j + 2 , i--;
        }

        isUp = !isUp;
    }


    //LENTROL
    i = 0, j = 0 ;

    isUp = true;

    for (int k=0; k<n*n;)
    {
        if (isUp)
        {
            for ( ; i>=0 && j<n ; j++, i--)
            {
                if (table[SIZE-i+2][SIZE-j+2])
                {
                    b.setX(SIZE-i+2); // !!! a SIZE - i erteket kell bele tenni !!!
                    b.setY(SIZE-j+2);
                    k=n*n;
                }
                k++;
            }

            if (i < 0 && j<=n-1)
                i = 0;
            if (j == n)
                i = i+2 , j--;
        }

        else
        {
            for ( ; j >= 0 && i<n ; i++ , j--)
            {
                if (table[SIZE-i+2][SIZE-j+2])
                {
                    b.setX(SIZE-i+2); // !!!itt is !!!
                    b.setY(SIZE-j+2);
                    k=n*n;
                }
                k++;
            }

            if (j < 0 && i<=n-1)
                j = 0;
            if (i == n)
                j = j + 2 , i--;
        }

        isUp = !isUp;
    }

    cout << endl <<"(" << a.getX() << "," << a.getY() << ")"<< "&" << "(" << b.getX() << "," << b.getY() << ")" << endl;

    return sqrt((b.getX()-a.getX())*(b.getX()-a.getX()) + (b.getY()-a.getY())*(b.getY()-a.getY()));
}




///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double distance(int ax, int ay, int bx, int by)
{
    return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}




///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//3-as feladat
bool my_cmp(const Pont& a, const Pont& b)
{
    //novekvo sorrend
    return a.getX()<b.getX();
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sorting(vector<Pont>& tomb)
{
    sort(tomb.begin(), tomb.end(), my_cmp);
    int i;

    for (i=0; i<N; ++i)
    {
        cout << "x=" <<tomb[i].getX() << " " << "y=" <<tomb[i].getY() << endl;
    }
}




///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//4-es feladat
Pont* findtenpoints(bool **table, int n)
{
    Pont* res=(Pont*)malloc(10*sizeof(Pont));
    int it=0;

    int i = 0, j = 0 ;

    bool isUp = true;

    for (int k=0; k<n*n;)
    {
        if (isUp)
        {
            for ( ; i>=0 && j<n ; j++, i--)
            {
                if (table[SIZE-i+2][SIZE-j+2])
                {
                    res[it].setX(SIZE-i+2);
                    res[it].setY(SIZE-j+2);
                    ++it;
                }
                if (it==10)
                {
                    k=n*n;
                }
                k++;
            }

            if (i < 0 && j<=n-1)
                i = 0;
            if (j == n)
                i = i+2 , j--;
        }
        else
        {
            for ( ; j >= 0 && i<n ; i++ , j--)
            {
                if (table[SIZE-i+2][SIZE-j+2])
                {
                    res[it].setX(SIZE-i+2);
                    res[it].setY(SIZE-j+2);
                    ++it;
                }
                if (it==9)
                {
                    k=n*n;
                }
                k++;
            }
            if (j < 0 && i<=n-1)
                j = 0;
            if (i == n)
                j = j + 2 , i--;
        }
        isUp = !isUp;
    }
    return res;
}