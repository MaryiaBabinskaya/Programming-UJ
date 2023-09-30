#include <iostream>
#include <vector>
using namespace std;
enum Odpowiedz{
    BAD_MARKED, BAD_UNMARKED, OK_MARKED, OK_UNMARKED
};
class Pytanie{
    vector<Odpowiedz> odpowiedzi;
public:
    Pytanie(vector<Odpowiedz> odpowiedzi): odpowiedzi(odpowiedzi){}
    int dobrych(){
        int n=0;
        for(unsigned i=0; i<odpowiedzi.size(); i++){
            if(odpowiedzi[i]==OK_MARKED)
                n++;
        }
        return n;
    }
    int blednych(){
        int n=0;
        for(unsigned i=0; i<odpowiedzi.size(); i++){
            if(odpowiedzi[i]==BAD_MARKED)
                n++;
        }
        return n;
    }
    int pustych_dobrych(){
        int n=0;
        for(unsigned i=0; i<odpowiedzi.size(); i++){
            if(odpowiedzi[i]==OK_UNMARKED)
                n++;
        }
        return n;
    }
    int pustych(){
        int n=0;
        for(unsigned i=0; i<odpowiedzi.size(); i++){
            if(odpowiedzi[i]==BAD_UNMARKED||odpowiedzi[i]==OK_UNMARKED)
                n++;
        }
        return n;
    }
    Odpowiedz getOdpowiedz(int i){
        return odpowiedzi[i];
    }
};
class Oceniacz{
public:
    virtual int ocen( Pytanie &p) = 0;
};
class OceniaczPojedynczyWybor: public Oceniacz{
     int ocen( Pytanie &pytanie) override{
        if(pytanie.dobrych()==1 && pytanie.pustych_dobrych()==0) //1pkt jeśli zaznaczono tylko jedno pole i była to poprawna odpowiedź
            return 1;
        else
            return 0;
    }
};
class OceniaczWielokrotnyWybor :public Oceniacz{
    int ocen( Pytanie& pytanie) override{
        if(pytanie.blednych()==0&&pytanie.dobrych()==0) //0pkt jeśli nie zaznaczono żadnej odpowiedzi
            return 0;
        if(pytanie.blednych()>=1) //-1pkt jeśli zaznaczono chociaż jedną złą odpowiedź
            return -1;
        if(pytanie.pustych_dobrych()!=0&&pytanie.dobrych()>=1&&pytanie.blednych()==0) //1pkt jeśli zaznaczono chociaż jedną poprawną odpowiedź, ale nie wszystkie poprawne oraz nie zaznaczono złej odpowiedzi
            return 1;
        if(pytanie.dobrych()>=1&&pytanie.pustych_dobrych()==0&& pytanie.blednych()==0) //2pkt jeśli zaznaczono wszystkie dobre odpowiedzi i żadnej złej
            return 2;
        
        return 100;
    }
};
class Osoba{
    string imie;
    string nazwisko;
};
class Test{
    vector<Pytanie> pytania;
    Osoba osoba;
public:
    Test(vector<Pytanie>& pytania, Osoba o): pytania(pytania), osoba(o) {}
    int ocen(Oceniacz& o){
        int res=0;
        for(Pytanie &pytanie: pytania){
            res+=o.ocen(pytanie);
        }
        return res;
    }
    Osoba getOsoba(){
        return osoba;
    }
    Pytanie getPytanie(int i){
        return pytania[i];
    }
    void setPytanie(int i, Pytanie& pyt){
        pytania[i]=pyt;
    }
};

int main() {
    Pytanie pyt1=  Pytanie(vector<Odpowiedz>{BAD_MARKED,OK_UNMARKED, OK_MARKED });
    Pytanie pyt2=  Pytanie(vector<Odpowiedz>{OK_MARKED,BAD_MARKED, OK_MARKED });
    Pytanie pyt3=  Pytanie(vector<Odpowiedz>{OK_MARKED,OK_MARKED, BAD_MARKED });
    Pytanie pyt4=  Pytanie(vector<Odpowiedz>{OK_MARKED,OK_MARKED, OK_MARKED });
    Pytanie pyt5=  Pytanie(vector<Odpowiedz>{OK_MARKED,BAD_UNMARKED, OK_MARKED });
    Pytanie pyt6=  Pytanie(vector<Odpowiedz>{OK_MARKED,OK_MARKED, OK_MARKED });
    vector<Pytanie> v =vector<Pytanie>({pyt1,pyt2, pyt3, pyt4, pyt5, pyt6});
    Osoba osoba;
    OceniaczWielokrotnyWybor k;
    Test test1 = Test(v, osoba);
    cout<<test1.ocen(k)<<endl;
    Pytanie pyt10 = Pytanie(vector<Odpowiedz>{BAD_MARKED, OK_UNMARKED});
    Pytanie pyt11 = Pytanie(vector<Odpowiedz>{BAD_UNMARKED, OK_MARKED});
    Pytanie pyt12 = Pytanie(vector<Odpowiedz>{BAD_UNMARKED, OK_UNMARKED});
    OceniaczPojedynczyWybor p;
    vector<Pytanie> t= vector<Pytanie>({pyt10, pyt11, pyt12});
    Test test2 = Test(t, osoba);
    cout<<test2.ocen(p)<<endl;
    return 0;
}
