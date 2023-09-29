//Maryia Babinskaya
package zadanie4.ogrzewanie;
import zadanie4.UzywajacyZegara;
import zadanie4.czas.PoraDoby;
import zadanie4.czas.PrzelicznikCzasu;
import zadanie4.sensory.SensorNiedostepny;
import zadanie4.sensory.Zegar;
import java.util.Vector;
public class ZmiennotemperaturoweSterowanieOgrzewaniem
        extends StalotemperaturoweSterowanieOgrzewaniem
        implements UzywajacyZegara {
    Zegar zegar;
    Vector <PoraDoby> tabPory;
    Vector <Double> tabtemp;
    public ZmiennotemperaturoweSterowanieOgrzewaniem(){
        tabPory = new Vector<>();
        tabtemp = new Vector<>();
    }
    public void sprawdzSensory() throws SensorNiedostepny {
        double tmp = docelowaTemperatura;
        for(int i = 0; i < tabPory.size(); i++){
            if(tabPory.get(i).zawieraSie(PrzelicznikCzasu.sekundaDnia(zegar.pobierzCzas()))){
                docelowaTemperatura = tabtemp.get(i);
                break;
            }
        }
        super.sprawdzSensory();
        docelowaTemperatura = tmp;
    }
    public void dodajOkresZezmienionaTemperatura(PoraDoby pora, double temperatura)
            throws NiejednoznaczaTemperatura{
         for(int i = 0; i < tabPory.size(); i++){
             if(tabPory.get(i).przecinanie(pora)){
                 if(tabtemp.get(i) != temperatura) throw new NiejednoznaczaTemperatura(tabPory.get(i),"");
             }
         }
         tabPory.add(pora);
         tabtemp.add(temperatura);
    }
    public void ustawZegar(Zegar _zegar){
        zegar = _zegar;
    }
}