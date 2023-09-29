// Maryia Babinskaya
#ifndef Polynomial_H
#define Polynomial_H
#include "Z3.h"
#include <iostream>
class Polynomial{
  public:
     unsigned int stopien;
     Z3* k; //tabelka z wspolczynnikami
     Polynomial(); //konstruktor domyslny
     Polynomial(unsigned int stopien, Z3* k);//konstruktor z argumentem typu unsigned int oraz tablicą obiektów Z3
     Polynomial(const Polynomial& poly); //konstruktor kopiujacy
    ~Polynomial(); 

     Z3& operator[](const unsigned int i) const;
 
     Polynomial& operator=(const Polynomial& poly);
     Polynomial& operator+=(const Polynomial poly);    
     Polynomial& operator-=(const Polynomial& poly);
     Polynomial& operator*=(const Polynomial& poly);
     Polynomial& operator*=(const Z3& num);
     Polynomial& operator/=(const Z3& num);
     
     unsigned int degree()const;
     std::string toString(const std::string& xVar);
};
     Polynomial operator+(Polynomial Poly1, const Polynomial& Poly2);
     Polynomial operator-(Polynomial Poly1, const Polynomial& Poly2);
     Polynomial operator*(Polynomial Poly1, const Polynomial& Poly2);
     
     Polynomial operator*(const Z3& num, const Polynomial& Poly);
     Polynomial operator/(const Polynomial& Poly, const Z3& num);
     
     void mod( const Polynomial& u, const Polynomial& v,  Polynomial& q,  Polynomial& r);
     std::ostream& operator<<(std::ostream& out, const Polynomial& Poly);
     std::istream& operator>>(std::istream& in,  Polynomial& Poly);
     
#endif
