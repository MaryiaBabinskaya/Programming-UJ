//Maryia Babinskaya
package zadanie4.ogrzewanie;
import zadanie4.czas.PoraDoby;
public class NiejednoznaczaTemperatura extends java.lang.Exception {
    PoraDoby pora;
    String sms;
    public NiejednoznaczaTemperatura(){
        sms = "";
    }
    public NiejednoznaczaTemperatura(PoraDoby konflikt, java.lang.String message){
        pora = konflikt;
        sms = message;
    }
    public PoraDoby pobierzKonflikt(){
        return pora;
    }
}