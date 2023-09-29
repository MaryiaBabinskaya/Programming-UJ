// Maryia Babinskaya
#include "Z3.h"

  unsigned int dodatkowaFunkcja_zwracajaca012(int liczba1){
	if ( liczba1 >= 0){                    
		return liczba1%3;
    }
    if ( liczba1 < 0){
	  if(liczba1%3 == -1) return 2;
	  if(liczba1%3 == -2) return 1;
	  if(liczba1%3 == 0)  return 0;
    } 
    return 0;
  }
  
 Z3::Z3(){   //konstruktor, tworzy liczbę zero
  liczba = 0;                           
 }
 Z3::Z3(short int liczba1){   // tworzy liczbe Z3 na podstawie podanego argumentu
  liczba = dodatkowaFunkcja_zwracajaca012(liczba1);                   
 }
 Z3::Z3(const Z3& num){ //konstruktor copy
	 liczba = num.liczba;
 }
 Z3::operator short int () const {return (short int)liczba;} //zwraca typ short int

  Z3 operator+(Z3 a, const Z3 b){ //operator +
	a.liczba =  a.liczba + b.liczba; 
    return Z3(a.liczba);
  }
  Z3 operator-(Z3 a, const Z3 b){ //operator -
	a.liczba = a.liczba - b.liczba;
    return Z3(a.liczba);
  }
  Z3 operator*(Z3 a, const Z3 b){ //operator *
	a.liczba = a.liczba * b.liczba;
    return Z3(a.liczba);
  }
  Z3 operator/(Z3 a, const Z3 b){ //operator /
	  
	if(b.liczba == 0){ 
		 std::cout<<"Dzielenie przez zero\n";
		 return Z3(a.liczba);
	}
    else{
    if(a.liczba==2 && b.liczba==1) return Z3(2);
    if(a.liczba==2 && b.liczba==2) return Z3(1);
    if(a.liczba==0) return Z3(0);
    if(a.liczba==1 && b.liczba==2) return Z3(2);
    if(a.liczba==1 && b.liczba==1) return Z3(1);
    }
     return Z3(0); //do tego nie dojdziemy
  }
  std::ostream& operator<<(std::ostream& out, const Z3& a){ //operator <<
	  out << a.liczba;
	  return out;
  }
 Z3& Z3::operator=(const Z3& num){
     if (this == &num){
        return *this;
     }
     else{
      this->liczba=num.liczba;
     }
      return *this;
 }
 Z3& Z3::operator+=(const Z3& num){ // & bo potrzebowali z tresci 
	 unsigned int result = liczba + num.liczba;
	 result = dodatkowaFunkcja_zwracajaca012(result);
	 this-> liczba = result;
      return *this;
     }
 Z3& Z3::operator-=(const Z3& num){
     unsigned int result = liczba - num.liczba;
	 result = dodatkowaFunkcja_zwracajaca012(result);
	 this-> liczba = result;
      return *this;
     }
 Z3& Z3::operator*=(const Z3& num){
     unsigned int result = liczba * num.liczba;
	 result = dodatkowaFunkcja_zwracajaca012(result);
	 this-> liczba = result;
      return *this;
 }
 Z3& Z3::operator/=(const Z3& num){	
	if(num.liczba == 0){
		std::cout<<"Dzielenie przez zero\n";
		return *this;
	}
    if(liczba==1 && num.liczba==2) liczba=2;
    else if(liczba==2 && num.liczba==2) liczba=1;
    return *this;
 }
