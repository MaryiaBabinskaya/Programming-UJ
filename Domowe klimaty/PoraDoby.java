//Maryia Babinskaya
package zadanie4.czas;
public class PoraDoby extends java.lang.Object {
    int poczatek;
    int koniec;
    public PoraDoby(){
        poczatek = 0;
        koniec = 0;
    }
    public PoraDoby(int poczatekSekunda, int koniecSekunda){
        poczatek = poczatekSekunda;
        koniec = koniecSekunda;
    }
    public void ustawPoczatek(int _poczatek){
        poczatek = _poczatek;
    }
    public void ustawKoniec(int _koniec){
       koniec = _koniec;
    }
    public int pobierzPoczatek(){
        return poczatek;
    }
    public int pobierzKoniec(){
        return koniec;
    }
    public boolean zawieraSie(int sekundaDnia) {
    if(poczatek <= koniec){
     if(poczatek <= sekundaDnia && sekundaDnia < koniec){return true;}
        else return false;
     }
     else{
        if(poczatek <= sekundaDnia || sekundaDnia < koniec){return true;}
        else return false;
     }
    }
    public int dlugosc(){
        if (poczatek < koniec) return (koniec - poczatek);
        else if (poczatek > koniec) return ( 86400 - poczatek + koniec);
        else return 0;
    }
    public boolean przecinanie(PoraDoby pora){ //dodatkowa
        if(zawieraSie(pora.pobierzKoniec()-1) || zawieraSie(pora.pobierzPoczatek()) || pora.zawieraSie(pobierzPoczatek()) || pora.zawieraSie(pobierzKoniec()-1))
            return true;
        return false;
    }
}