// Maryia Babinskaya
#ifndef Z3_H
#define Z3_H
#include <iostream>
unsigned int dodatkowaFunkcja_zwracajaca012(int x);
class Z3{
  public:
    unsigned int liczba;
    
    Z3(); //konstruktor domyslny
    Z3(short int x); //konstruktor z argumentem typu short int
    Z3(const Z3& num); //konstruktor copy
    
	operator short int()const; //operator konwersji do short int
	Z3& operator=(const Z3& num);
    Z3& operator+=(const Z3& num);    
    Z3& operator-=(const Z3& num);
    Z3& operator*=(const Z3& num);
    Z3& operator/=(const Z3& num);
    
};

     std::ostream& operator<<(std::ostream& out, const Z3& a); //funkcje globalne
     Z3 operator+(Z3 a, const Z3 b);
     Z3 operator-(Z3 a, const Z3 b);
     Z3 operator*(Z3 a, const Z3 b);
     Z3 operator/(Z3 a, const Z3 b);

#endif 
