#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED

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

#endif // PONT_H_INCLUDED
