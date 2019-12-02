// Pont.h – interfész
#pragma once
#ifndef PONT_H
#define PONT_H

#include<algorithm>
class Pont {
private:
	int x, y;
public:
	Pont(int x = 0, int y = 0);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void move(int nx, int ny);
	bool operator==(const Pont & other);
	
};
double distance(Pont a, Pont b);
int negyzet_e(Pont a, Pont b, Pont c, Pont d);
Pont* p_gen(int n);
//bool cmp_x(const Pont &a, const Pont &b);
//bool cmp_y(const Pont &a, const Pont &b);

#endif /* PONT_H */