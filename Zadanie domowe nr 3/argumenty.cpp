//moj kompilator zwraca float jak double
#include <iostream>
#include <cstdarg>
#include <math.h>


using namespace std;
//////////////////////////////////////////////////////////////////////////
double SUMA(const char* typy, ...){ //wypisuje SUMA
	int i;
	//float f;
	double d;
	va_list ap;
	va_start(ap, typy); //typy - ostatni argument przed kropkami
	int j = 0;
	char c = typy[0];
	
	double suma = 0;
	while (c!= '\0'){
		switch (c){
		case 'i':
			i = va_arg(ap, int);
			//cout << "SUMA int   : " << i << endl;
			suma += (double)i;
			break;
		
		case 'd':
			d = va_arg(ap, double);
			suma += (double)d;
			//cout << "SUMA double  : " << d << endl;
			break;

			va_end(ap);
		  
		}
		j++;
		c=typy[j];
	}

	cout << endl;
	va_end(ap);
	
	return suma;
}
////////////////////////////////////////////////////////////////////////////
double ARYtMETYCZNA(const char* typy, ...){ //wypisuje arytmetyczna
	int i;
	//float f;
	double d;
	va_list ap;
	va_start(ap, typy); //typy - ostatni argument przed kropkami
	int j = 0;
	char c = typy[0];
	
	double suma = 0;
	while (c!= '\0'){
		switch (c){
		case 'i':
			i = va_arg(ap, int);
			
			//cout << "SUMA int   : " << i << endl;
			suma += (double)i;
			break;
		
		case 'd':
			d = va_arg(ap, double);
			suma += (double)d;
			//cout << "SUMA double  : " << d << endl;
			break;

	
			va_end(ap);
		  
		}
		j++;
		c=typy[j];
	}

	cout << endl;
	va_end(ap);
	
	return suma/j;
}
///////////////////////////////////////////////////////////////////////////////////////

double GEOMETRYCZNA(const char* typy, ...){ //wypisuje arytmetyczna
	int i;
	//float f;
	double d;
	va_list ap;
	va_start(ap, typy); //typy - ostatni argument przed kropkami
	int j = 0;
	char c = typy[0];
	
	double suma = 0;
	while (c!= '\0'){
		switch (c){
		case 'i':
			i = va_arg(ap, int);
			
			//cout << "SUMA int   : " << i << endl;
			suma += (double)i;
			break;
		
		case 'd':
			d = va_arg(ap, double);
			suma += (double)d;
			//cout << "SUMA double  : " << d << endl;
			break;

	
			va_end(ap);
		  
		}
		j++;
		c=typy[j];
	}

	cout << endl;
	va_end(ap);
	
	return pow(suma,1.0/j);
}
///////////////////////////////////////////////////////////////////////////////////////

double harmoniczna(const char* typy, ...){ //wypisuje arytmetyczna
	int i;
	//float f;
	double d;
	va_list ap;
	va_start(ap, typy); //typy - ostatni argument przed kropkami
	int j = 0;
	char c = typy[0];
	
	double suma = 0;
	while (c!= '\0'){
		switch (c){
		case 'i':
			i = va_arg(ap, int);
			
			//cout << "SUMA int   : " << i << endl;
			suma += (double)1/i;
			break;
		
		case 'd':
			d = va_arg(ap, double);
			suma += (double)1/d;
			//cout << "SUMA double  : " << d << endl;
			break;

	
			va_end(ap);
		  
		}
		j++;
		c=typy[j];
	}

	cout << endl;
	va_end(ap);
	
	return j/suma;
}
///////////////////////////////////////////////////////////////////////
void zaprezentujArgumenty(const char* typy, ...){    //prosto wypisuje
	int i;
	//float f;
	double d;
	va_list ap;
	va_start(ap, typy); //typy - ostatni argument przed kropkami
	int j = 0;
	char c = typy[0];
	while (c!= '\0'){
		switch (c){
		case 'i':
			i = va_arg(ap, int);
			cout << "Liczba int   : " << i << endl;
			break;
		//case 'f':
		//	f = va_arg(ap, float);
		//	cout << "Liczba float: " << f << endl;
		//	break;
		case 'd':
			d = va_arg(ap, double);
			cout << "Liczba double  : " << d << endl;
			break;
		default:
			cout << "Nieprawidlowy kod typu" << endl << endl;
			va_end(ap);
		    return;
		}
		j++;
		c=typy[j];
	}

	cout << endl;
	va_end(ap);
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
	zaprezentujArgumenty("iddi", 7, 4.9, 3.9, 10);
	double suma = SUMA("iddi", 7, 4.9, 3.9, 10);
	cout <<"SUMA: "<< suma<<endl;
	double arytm = ARYtMETYCZNA("iddi", 7, 4.9, 3.9, 10);
    cout <<"ARYTMETYCZNA: "<< arytm<<endl;
    double geom = GEOMETRYCZNA("iddi", 7, 4.9, 3.9, 10);
	cout <<"GEOMETRYCZNA: "<< geom<<endl;
	double harm = harmoniczna("iddi", 7, 4.9, 3.9, 10);
	cout <<"HARMONICZNA: "<< harm<<endl;
	cin.ignore();
	return 0;
}

