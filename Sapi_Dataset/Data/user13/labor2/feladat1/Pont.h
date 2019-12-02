// Pont.h – interfész
#ifndef PONT_H
#define PONT_H
#include <vector>

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
	double origo_tavolsag(vector <double> pontok);
};
int negyzet_e(Pont a, Pont b, Pont c, Pont d);
vector <Pont> random_pontok(int n);

#endif /* PONT_H */