//Maryia Babinskaya
#include <iostream>
using namespace std;

bool mniej_niz_jeden(unsigned int n, const double *p){        //pomocnicza dla 1 punkta
   double suma=0;                                             //p[0]+...+p[n-1]<1 sprawdza ten warunek
     for(unsigned int i=0;i<n;i++){
	   suma=suma+*(p+i);
     }
   double q=0;
     for(unsigned int i=0;i<n;i++){                           //p[i]>=0 dla i=0,1,2,...,n-1
       if(*(p+i)>=0){
		q++;
	   } 
     }
   
   if(suma<1 && q==n ){
		return true;
		}
   else{
		return false;
	}
}
   
bool expval(unsigned int n, const double *x, const double *p, double (*f)(double), double (&r) ){ 
	             //funkcja expval ma obliczyć wartość wyrażenia f(x[0])p[0]+... +f(x[n-1])p[n-1] + f(x[n])(1-p[0]-...-p[n-1]) i podstawić wynik do zmiennej r
                                              //Zakładamy, że pod adresem x znajduje się tablica o rozmiarze n+1, 
                                              //natomiast pod adresem p znajduje się tablica o rozmiarze n
	   if(mniej_niz_jeden(n,p)==true){        
		double promezhutocznaja1=0;
		for(unsigned int j=0;j<n;j++){     //g(x[0])p[0]+... +g(x[n-1])p[n-1]= promezhutocznaja1 DONE  //f=g takie samo, bo double g(double x) { return 7*x-2; }
		 promezhutocznaja1=promezhutocznaja1+f(*(x+j))*p[j];
		}   
	    double promezhutocznaja2=1;
		  for(unsigned int j=0;j<n;j++){      //(1-p[0]-...-p[n-1]) = promezhutocznaja2 DONE           
		    promezhutocznaja2=promezhutocznaja2-(*(p+j)); 
		  }
		double promezhutocznaja3=0;                     //g(x[n]) = promezhutocznaja3 DONE
		 promezhutocznaja3=f(x[n])*promezhutocznaja2;
		
		r = promezhutocznaja1+promezhutocznaja3;
      return true;
      }
      else{
		  return false;
		   }

}

int sort(int *ar, unsigned int N){               //szybkie sortowanie (ShellSort)
 for (unsigned int gap = N/2; gap > 0; gap /= 2) //Start with a big gap, then reduce it
    for (unsigned int i = gap; i < N; ++i) {
        int tmp = ar[i];
        unsigned int j = i;
        for (; j >= gap && tmp < ar[j-gap]; j -= gap)
            ar[j] = ar[j-gap];
        ar[j] = tmp;
    }
  return *ar;
}
        
bool median(unsigned int n, const int *t, int (*f)(int), bool (*p)(int), double (&r)){ 
  unsigned int N=0;
   for(unsigned int i=0;i<n;i++){
	if(p(t[i])){
		N++;                 //rozmiar tabelki, ktora pasuje pod tresc
   }}
	if(N==0){                //jezeli pusto
		return false;
	}
	else{
		int j=0;
		int* tab0= new int[N];   //pomocnicza
		  for(unsigned int i=0;i<n;i++){
			if(p(t[i])){
				tab0[j]=f(t[i]);    //zapolniajem tablicu, tolko tem czto podchodit
				j++;
			}
		  }
	    sort(tab0,N); //sortowanie od mniejszego do wiekszego   
	      int dublikaty = 0;
         for (unsigned int i = 1; i < N; i++){
         if (tab0[i] == tab0[i-1]) ++dublikaty;}    //schitaet kol-vo dublikatow
           int nowa_dlugosc=N-dublikaty;//bez dublikatow
           int d=0;
           int* tab2 = new int[nowa_dlugosc];
             for(unsigned int i=0;i<N-1;i++){ //odzrucanie dublikatow
                if(tab0[i]!=tab0[i+1]){
                    tab2[d]=tab0[i];
                    ++d;
                }          
             }
        tab2[nowa_dlugosc-1]=tab0[N-1];  //tak jak wyzej bylo i=0,n<1    NIE WIEM DLACZEGO NA SAMYM POCZATKU NIE ZROBILAM N<1  
		double mediana=0.0;
		  if((N-dublikaty)%2!=0){		     //parzyste
			                                 //średnia liczb an/2 oraz an/2+1, gdy n jest liczbą parzystą
			  mediana=tab2[(N-dublikaty+1)/2-1];
			  r=mediana;  
		  }
		  else{                              //nie parzyste
			                                 //liczba a(n+1)/2 gdy n jest liczbą nieparzystą
			mediana=(float(tab2[(N-dublikaty)/2-1]+tab2[(N-dublikaty)/2+1-1]))/2;
			r=mediana;   
		  }
		delete [] tab0;
		delete [] tab2;  
        return true; 
	  } 
}

int gcd1(int a,int b) {
   int temp;
   while(b > 0) {
      temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}

unsigned int gcd(unsigned int n, const int *t, int *r = nullptr){   //Zadaniem funkcji jest obliczenie największego wspólnego dzielnika zbioru liczb Z = { t[i] : t[i]!=0 }       
	  int wsp; 
	  unsigned int proverka_na_pusto=0;
         for(unsigned int i=0;i<n;i++){
		  if(t[i]==0){
			proverka_na_pusto++;                   //proverka w celom chtoby byl nie pustoj zbior, tut count nuli
		  }
	    }                                             
	  if(proverka_na_pusto==n){return 0;}              // jesli pustoj zbior to 0
	 else {                                  //jesli zbior nie pustoj, ignorim 0 i cchitaem NOD 
           wsp = t[0];
           for(unsigned int i=1; i<n; i++) {
             wsp = gcd1(wsp, t[i]);
           }
           return wsp;
          
      if(r!=nullptr){                          //tablica r
       for(unsigned int i=0;i<n;i++){          //należy do tablicy r przepisać (z zachowaniem kolejności) wszystkie elementy tablicy t podzielone przez
                                               //obliczony największy wspólny dzielnik zbioru Z.
         r[i]=t[i]/wsp;
       } 
      }
     }
}
     	 

 unsigned int count(unsigned int n, const int *t, bool (*p)(int,int)=nullptr){
    unsigned int w=0;
    if(n==0){   //pusty zbior
		w=0;
		return w;
	}
    int dublikaty=0; //ilosc dublikatow
    int* tab0=new int[n];
    for(unsigned int i=0;i<n;i++){ //perepis w raboczuju 
            tab0[i]=t[i];
        }
    sort(tab0,n);//sortowanie
    for(unsigned int i=0;i<n-1;i++){//ilosc dublikatow
            if(tab0[i]==tab0[i+1]){
                ++dublikaty;
            }
    }
    int M=n-dublikaty;//ilosc bez dublikatow(nowy rozmiar)
    int j=0;
    int* Z = new int[M];//nowa tab z nuzhnym rozmiarem
    for(unsigned int i=0;i<n-1;i++){ //odzrucanie dublikatow
            if(tab0[i]!=tab0[i+1]){
                Z[j]=tab0[i];
                ++j;                
            }
    }
   Z[M-1]=tab0[n-1]; //tak jak wyzej bylo i=0,n<1    NIE WIEM DLACZEGO NA SAMYM POCZATKU NIE ZROBILAM n<1 
    if(p==nullptr){   //Jeśli wskaźnik p jest równy nullptr, to funkcja ma obliczyć i zwrócić liczbę elementów zbioru Z = { (t[i],t[j]) : i,j=0,...,n-1 }
        w=M*M;
    }
    else{                    //Gdy p jest różne od nullptr, to należy zwrócić liczbę elementów zbioru Z = { (t[i],t[j]) : p(t[i],t[j])=true, i,j=0,...,n-1 }        
        for(int i=0;i<M;i++){
            for(int k=0;k<M;k++){
                if(k!=i && p(Z[i],Z[k])){
                    ++w;
                }
            }
            if(p(Z[i],Z[i])){
                ++w;
            }
        }
    }
    delete[] tab0;
    delete[] Z;
    return w;
}  
////////////////////////////////////////////////////////////////////////

int f(int x) { return x*(x-10); }
bool TRUE(int x) { return true; }
bool EVEN(int x) { return x%2==0; }
bool ASYMMETRIC_REL(int a, int b) { return 3*a<b; }
double g(double x) { return 7*x-2; }
int main(){
double r=0.0;
int t[] = {6,30,12,-81,9,-9,15,6,30,33,21,18};
unsigned n = sizeof(t)/sizeof(int);
cout << boolalpha;
cout << median(n,t,f,TRUE,r) << endl;
cout << "median_all=" << r << endl;
cout << median(n,t,f,EVEN,r) << endl;
cout << "median_even=" << r << endl;
cout << "gcd=" << gcd(n,t) << endl;
cout << "count=" << count(n,t,ASYMMETRIC_REL) << endl;
double x[] = {4,3,2,1};
double p[] = {0.125,0.25,0.125};
cout << expval(3,x,p,g,r) << endl;
cout << "expval=" << r << endl;
}
