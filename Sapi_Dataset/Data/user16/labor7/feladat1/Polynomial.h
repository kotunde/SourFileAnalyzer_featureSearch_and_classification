#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;
class Polynomial
{
// Polinom egy�tthat�i
    double *coefficients;
// Polinom egy�tthat�inak a sz�ma
    int capacity;
public:
    static int db;
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &that);
    Polynomial(Polynomial &&that);
    ~Polynomial();
// Polinom foksz�ma
    int degree() const;
// Polinom �rt�ke a megadott pontban
    double evaluate(double x) const;
// Polinom deriv�ltja
    static int pdsz()
    {
        return db;
    }
    Polynomial derivative() const;
    double operator[](int index) const;
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
    friend ostream & operator <<(ostream& out, const Polynomial& what);
    /* copy assignment - m�ly m�solat letilt�sa �rt�kad�sra n�zve */
    Polynomial& operator=(const Polynomial&) = delete;
    /* move assignment - sek�ly m�solat letilt�sa �rt�kad�sra n�zve */
    Polynomial& operator=(Polynomial&&) = delete;
};


#endif
