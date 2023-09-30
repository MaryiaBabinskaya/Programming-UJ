#include <iostream>
#include <string>

using namespace std;

class Przedmiot{
	
		private:
	 
	        string m_nazwa;
	        int m_waga;
	        int m_szerokosc;
		        
	 public:
	        
     Przedmiot(string nazwa, int waga, int szerokosc){
		 m_nazwa = nazwa ;
		 m_waga = waga;
		 m_szerokosc = szerokosc;
		 cout << "Tworzymy przedmiot:" << endl;
	 }
        
	string getNazwa() const { return m_nazwa; }
	void setNazwa( string nazwa ) { m_nazwa = nazwa; } 
	int getWaga() const { return m_waga; }
	void setWaga(int waga) { m_waga = waga; }
	int getSzerokosc() const { return m_szerokosc; }
	void setSzerokosc(int szerokosc) { m_szerokosc = szerokosc; }
	
};

class Ksiazka : public Przedmiot {
public:
    Ksiazka( string m_nazwa, int m_waga, int m_szerokosc) : Przedmiot(m_nazwa,m_waga,m_szerokosc){
		cout << "Tworzymy ksiazke:" << endl;
	}
};

class Plyta : public Przedmiot {
	
 private:
            string m_format;

 public:
    Plyta( string m_nazwa, int m_waga, int m_szerokosc, string m_format) : Przedmiot(m_nazwa,m_waga,m_szerokosc), m_format(m_format) {
		cout << "Tworzymy plyte:" << endl;
	}
};

class CD : public Plyta {
 public:
    CD( string m_nazwa, int m_waga, int m_szerokosc) : Plyta(m_nazwa,m_waga,m_szerokosc,"CD"){
		cout << "Tworzymy CD:" << endl;
	}
};

class DVD : public Plyta {
 public:
    DVD( string m_nazwa, int m_waga, int m_szerokosc) : Plyta(m_nazwa,m_waga,m_szerokosc,"DVD"){
		cout << "Tworzymy DVD:" << endl;
	}
};

class Polka {
	private:
	       int m_szerokosc;
	       int m_nośność;
	       int m_count_waga = 0;
	       int m_count_szerokosc = 0;

    public:	      
	Polka(  int m_szerokosc,  int m_nośność ):m_szerokosc(m_szerokosc), m_nośność(m_nośność){ 
		cout << "Tworzymy Polke:" << endl;
	}
	
	int getSzerokosc() const { return m_szerokosc; }
	int getNosnosc() const { return m_nośność; }
	
	void wtawianie(Przedmiot przedmiot){
		if ( m_count_waga < m_nośność && m_count_szerokosc < m_szerokosc) {
			 m_count_waga = m_count_waga + przedmiot.getWaga();
			 m_count_szerokosc = m_count_szerokosc + przedmiot.getSzerokosc();
		}
		else { cout << "Polka nie wytrzyma(" << endl; }
	}
	
	void zdejmowanie (Przedmiot przedmiot){
			 m_count_waga = m_count_waga - przedmiot.getWaga();
			 m_count_szerokosc = m_count_szerokosc - przedmiot.getSzerokosc();
	}
	
};

int main(){
	Ksiazka k1("Ksiazka_1",10,10);
	Ksiazka k2("Ksiazka_2",10,10);
	Ksiazka k3("Ksiazka_3",10,10);
	
	CD cd1("CD_1",10,10);
	
	Polka polka(100,100);

}
