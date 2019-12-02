#Lab3.h
//
// Created by tuni on 10/8/18.
//

#ifndef LABOR3_1_POINT_H
#define LABOR3_1_POINT_H

class Pont
{
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

#endif //LABOR3_1_POINT_H
