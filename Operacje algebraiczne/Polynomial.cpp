//Maryia Babinskaya
#include "Polynomial.h"
 Polynomial::Polynomial(){   //tworzy wielomian stopnia zero rowny zero
  stopien = 0;  
  k = new Z3[1];
  k[0]=Z3(0);                         
 }
 
 Polynomial::Polynomial(unsigned int _stopien,  Z3* _k){ //konstruktor tworzy wielomian 
     stopien = _stopien;
     k=new Z3[stopien+1];
     for(unsigned int i = 0; i<=stopien; i++)
	  k[i].liczba=_k[i].liczba;	 
	 
	 for(unsigned int i = stopien; i > 0; i--){  //wyrzucamy zera
		 if(k[i]==Z3(0)){
			 stopien--;
			 }
			 else break;
	 }
	 k=(Z3*)realloc(k,(stopien+1)*sizeof(Z3)); //zmienia rozmiar
 }
 
  Polynomial::Polynomial(const Polynomial& poly) : //konstruktor kopiujacy
  stopien(poly.stopien), k(new Z3[poly.stopien+1]) {
    for (unsigned int i = 0; i <= stopien; i++) {
        k[i] = poly.k[i];
    }
  } 
 
 Polynomial::~Polynomial(){
	  delete [] k;
  }

 Polynomial& Polynomial::operator=(const Polynomial& poly){
	    if (this == &poly){
          return *this;
        }
        else{
          delete [] k;
          stopien = poly.stopien;
          k = new Z3[stopien+1];
           for (unsigned int i = 0; i <=stopien; i++)
            k[i] = poly.k[i];
       }
    return *this;
 }

 unsigned int Polynomial::degree()const{
	 return stopien;
 }
 Z3& Polynomial::operator[](const unsigned int i) const{
	 if (i > stopien ){
		 std::cout<<"Niepoprawny indeks wielomianu\n";
		return k[0];
	 } 
      return k[i];
  }

////////////////////////////////////////////////////////////////////////
 Polynomial& Polynomial::operator+=(const Polynomial poly) {
      unsigned int new_stopien = (poly.stopien > this->stopien) ? poly.stopien : stopien;
    Z3 *new_k = new Z3 [new_stopien+1]; 

    for (unsigned int i = 0; i <= new_stopien; i++) {
        new_k[i] = Z3(0);
    }
    for (unsigned int i = 0; i <= poly.stopien; i++) {
        new_k[i] += poly.k[i];
    }
    for (unsigned int i = 0; i <= this->stopien; i++) {
        new_k[i] += this->k[i];
    }
    if(new_stopien==0){  //wielomian zerowy
        delete[]k;
        stopien=0;
        k=new Z3[1];
        k[0]=new_k[0];
        delete[]new_k;
        return *this;
    }
    delete [] k; 
   /* k = new_k;
    stopien = new_stopien;
    for(unsigned int i = stopien; i > 0; i--){  //wyrzucamy zera
		 if(k[i]==Z3(0)){
			 stopien--;
			 }
			 else break;
	 }
	 k=(Z3*)realloc(k,(stopien+1)*sizeof(Z3)); //zmienia rozmiar
    return *this;*/
    for(unsigned int i = new_stopien; i > 0; i--){  //wyrzucamy zera
		 if(new_k[i]==Z3(0)){
			 new_stopien--;
			 }
			 else break;
	 }
	new_k=(Z3*)realloc(new_k,(new_stopien+1)*sizeof(Z3)); //zmienia rozmiar
    this->stopien = new_stopien;
    this->k = new Z3 [stopien+1];
    for (unsigned int i = 0; i <= stopien; i++)
     this->k[i]=new_k[i];
    delete[]new_k;
     return *this;
 }
  Polynomial& Polynomial::operator-=(const Polynomial& poly) {
      unsigned int new_stopien = (poly.stopien > stopien) ? poly.stopien : stopien;
    Z3 *new_k = new Z3 [new_stopien+1]; 

    for (unsigned int i = 0; i <= new_stopien; i++) {
        new_k[i] = 0;
    }
    for (unsigned int i = 0; i <= stopien; i++) {
        new_k[i] = k[i];
    }
    for (unsigned int i = 0; i <= poly.stopien; i++) {
        new_k[i] -= poly.k[i];
    }
    if(new_stopien==0){  //wielomian zerowy
        delete[]k;
        stopien=0;
        k=new Z3[1];
        k[0]=new_k[0];
        delete[]new_k;
        return *this;
    }
    delete [] k; 
   /* k = new_k;
    stopien = new_stopien;
    for(unsigned int i = stopien; i > 0; i--){  //wyrzucamy zera
		 if(k[i]==Z3(0)){
			 stopien--;
			 }
			 else break;
	 }
	 k=(Z3*)realloc(k,(stopien+1)*sizeof(Z3)); //zmienia rozmiar
    return *this;*/
    for(unsigned int i = new_stopien; i > 0; i--){  //wyrzucamy zera
		 if(new_k[i]==Z3(0)){
			 new_stopien--;
			 }
			 else break;
	 }
	new_k=(Z3*)realloc(new_k,(new_stopien+1)*sizeof(Z3)); //zmienia rozmiar
    stopien = new_stopien;
    k = new Z3 [stopien+1];
    for (unsigned int i = 0; i <= stopien; i++)
     k[i]=new_k[i];
    delete[]new_k;
     return *this;
 }
 
 
 
 
 Polynomial& Polynomial::operator*=(const Polynomial& poly){///////////////////////////////dodelat
	 return *this;
 }
 
 
 
 Polynomial& Polynomial::operator*=(const Z3& num) {
    for (unsigned int i = 0; i <= stopien; i++) 
        k[i] *= num;
    return *this;
 }
 Polynomial& Polynomial::operator/=(const Z3& num) {
	if(num.liczba==0){
	  std::cout<<"Dzielenie przez zero\n";
	  return *this;
	}
    for (unsigned int i = 0; i <= stopien; i++) 
        k[i] /= num;
    return *this;
 }

////////////////////////////////////////////////////////////////////////
Polynomial operator+(Polynomial Poly1, const Polynomial& Poly2){ //operator +
	Poly1 += Poly2;   
    return Poly1;
  }
  Polynomial operator-(Polynomial Poly1, const Polynomial& Poly2){ //operator -
   Poly1 -= Poly2;
   return Poly1;
  }
  Polynomial operator*(Polynomial Poly1, const Polynomial& Poly2){ //operator *	  
   return Poly1;
  }
 
  Polynomial operator*(const Z3& num, const Polynomial& Poly){
    return Poly;
  }
  Polynomial operator/(const Polynomial& Poly, const Z3& num){
	return Poly;
  }
////////////////////////////////////////////////////////////////////////

  void mod(const Polynomial& u, const Polynomial& v, Polynomial& q, Polynomial& r){  }

  
  std::ostream &operator << (std::ostream &out, const Polynomial& poly) {
    out<<"{"<<poly.k[0];
    for(unsigned int i = 1;i<=poly.stopien;i++)
        out<<","<<poly.k[i];
    out<<"}";
    return out;
  }
  
  std::istream& operator>>(std::istream& in, Polynomial& Poly){
	  std::string s,rest;
	  getline(in,rest,'{');  //stream(potok dannych)/string/separator(razdilitel) 
	  getline(in,s,'}');     //sczitywajet iz potoka simwoly
	  
	  delete [] Poly.k;
	  Poly.stopien = (s.length()/2); //bo przecinki
	  unsigned int koeficent = 0;
	  Poly.k=new Z3[Poly.stopien + 1];
	  for(unsigned long i = 0; i < s.length(); i=i+2){  //przepis
		  Poly.k[koeficent]=s[i];
		  koeficent++;
	  }
	 for(unsigned int i = Poly.stopien; i > 0; i--){  //wyrzucamy zera
		 if(Poly.k[i]==Z3(0)){
			 Poly.stopien--;
			 }
		 else break;
	 }
	 Poly.k=(Z3*)realloc(Poly.k,(Poly.stopien+1)*sizeof(Z3)); //zmienia rozmiar
		  return in;
  }

   std::string Polynomial::toString(const std::string& xVar){
	 unsigned int count_zera = 0;
	 for(unsigned int i = 0; i <= stopien; i++){
		 if(k[i]==0) count_zera++;
     }
	 if(count_zera == stopien){   // zerowy wielomian
		return "0";
	 } 	 
	 if(k[0]!=0) { 
	    std::cout << k[0];
        for (unsigned int i = 1; i <= stopien; i++) {
            if (k[i] != 0) {
                std::cout << '+' << k[i] << "*" << xVar << '^' << i;
            }
        }
	 } 
	 else{
        if( count_zera <= stopien) {
            std::cout << k[count_zera] << "*" << xVar << '^' << count_zera;
        }
        for(unsigned int i = count_zera+1; i <= stopien;i++){
            if(k[i]!=0){
                std::cout<< '+' << k[i] <<"*" << xVar <<'^'<<i;
            }
        }
    }
    return "";           
 }
