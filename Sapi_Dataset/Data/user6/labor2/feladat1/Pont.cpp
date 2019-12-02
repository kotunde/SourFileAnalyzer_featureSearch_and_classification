#include "Pont.h"
#include <iostream>
using namespace std;

#include "Pont.h"
Pont::Pont(int x, int y) {
	if (x >= 0 && x <= 2000) this->x = x;
	else
		this->x = 0;
	if (y >= 0 && y <= 2000) this->y = y;
	else
		this->y = 0;
}
int Pont::getX() const {
	return x;
}
int Pont::getY() const {
	return y;
}
void Pont::setX(int x) {
	if (x >= 0 && x <= 2000) this->x = x;
}
void Pont::setY(int y) {
	if (y >= 0 && y <= 2000) this->y = y;
}
void Pont::move(int nx, int ny) {
	if (nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000) {
		this->x = nx;
		this->y = ny;
	}
}