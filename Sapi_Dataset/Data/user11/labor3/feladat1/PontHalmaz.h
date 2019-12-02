#ifndef PONTHALMAZ_H
#define PONTHALMAZ_H
#include "Pont.h"
#include <vector>
using namespace std;
class PontHalmaz{
 vector<Pont> pontok; //pontok
 int n; //k�l�nb�z� pontok sz�ma
 vector<double> tavolsagok; //pontok kozotti tavolsagok

 //seg�df�ggv�ny
 void tavolsagSzamitas();
public:
 PontHalmaz( int n = 100 ); //konstruktor: el��ll�tja a pontok t�mb�t,
//kisz�m�tja a t�vols�gokat (tavolsagok
//t�mb),

 double maxTavolsag() const; //maximum kiv�laszt�s a tavolsag t�mbb�l
 double minTavolsag() const; //minimum kiv�laszt�s a tavolsag t�mbb�l

 int tavolsagokSzama() const; //�sszesen h�ny t�vols�g �rtelmezhet� n
//k�l�nb�z� pont k�z�tt

 void printPontok() const; //a pontok t�rol� ki�rat�sa
 void printTavolsagok() const; //a tavolsagok t�rol� ki�rat�sa

 void rendezPontokX(); //n�vekv� sorrendbe rendezi a pontokat x
 //koordin�ta szerint
 void rendezPontokY(); //u. a. y koordin�ta szerint
 void rendezTavolsagok(); //a tavolsagok t�rol� rendez�se

 int kulonbozoTavolsagokSzama(); //h�ny darab k�l�nb�z� t�vols�got tartalmaz
//a tavolsagok t�mb
};
#endif /* PONTHALMAZ_H */
