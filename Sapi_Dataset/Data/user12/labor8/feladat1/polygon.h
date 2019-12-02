#ifndef POLYGON_H
#define POLYGON_H
#include <ostream>
using namespace std;
class Polygon {
struct Point {
Point *next;
double x;
double y;
};
Point *head = nullptr;
Point *tail = nullptr;
public:
Polygon(int copy, double *x, double *y);// .75p
Polygon(const Polygon &other); // .75p
Polygon(Polygon &&other); // .5p
~Polygon(); // .5p
Polygon &operator=(const Polygon &other); // .5p
Polygon &operator=(Polygon &&other); // .5p
const Point &operator[](int index) const; // .25p
Point &operator[](int index); // .25p
void append(double x, double y); // .5p
void translate(double dx, double dy); // .5p
double length(bool closed = false) const; // .5p
void bounds(double &xMin, double &yMin, double &xMax, double &yMax) const; // .5p
// concatenate two polygons
friend Polygon operator+(const Polygon &a, const Polygon &b); // .5p
friend ostream &operator<<(ostream &out, const Polygon &polygon); // .5p
};
#endif
