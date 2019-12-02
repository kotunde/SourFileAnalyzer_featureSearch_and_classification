//
// Created by tuni on 10/13/18.
//

#ifndef LABOR2_2_PONT_H
#define LABOR2_2_PONT_H

#define SIZE 1995

using namespace std;
#include <vector> //be kell include-olni !!!!

class Pont{
private:
    int x, y;
public:
    Pont( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void setX( int x );
    void setY( int y );
    void move( int nx, int ny);
};
double findmin(bool **,int);
double findmax(bool **,int);
double distance(int, int, int, int);

//3-as feladat
void sorting(std::vector<Pont> &);
Pont* findtenpoints(bool **,int);

#endif //LABOR2_2_PONT_H
