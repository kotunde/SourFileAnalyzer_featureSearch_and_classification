#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED

// Pont.h – interfész
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
 /* PONT_H */

#endif // PONT_H_INCLUDED
