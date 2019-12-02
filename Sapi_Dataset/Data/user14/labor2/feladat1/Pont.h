//
// Created by Tundi on 10/1/2018.
//

#ifndef LABOR2_1_PONT_H
#define LABOR2_1_PONT_H

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

#endif //LABOR2_1_PONT_H
