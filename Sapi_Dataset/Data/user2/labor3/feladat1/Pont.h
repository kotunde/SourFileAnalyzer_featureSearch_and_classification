// Pont.h – interfész
#pragma once
#ifndef PONT_H
#define PONT_H
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
	
	
};
double distance(Pont x, Pont y);
int negyzet_e(Pont a, Pont b, Pont c, Pont d);
Pont* p_gen(int n);

#endif /* PONT_H */