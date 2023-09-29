//Maryia Babinskaya
package zadanie4.wentylacja;
import zadanie4.UzywajacyZegara;
import zadanie4.sensory.Higrometr;
import zadanie4.sensory.Zegar;
public class WilgotnoscioweSterowanieWentylacja
        extends SterowanieWentylacja
        implements UzywajacyZegara {
    Higrometr higro;
    Zegar zegar;
    double wilgotnosc;
    public WilgotnoscioweSterowanieWentylacja(){}//?????????????????????
    public void ustawHigrometr(Higrometr higrometr){
        higro = higrometr;
    }
    public void ustawZegar(Zegar _zegar){
        zegar = _zegar;
    }
    public double getMaksymalnaPozadanaWilgotnosc(){
        return wilgotnosc;
    }
    public void ustawMaksymalnaPozadanaWilgotnosc(double maksymalnaPozadanaWilgotnosc){
        wilgotnosc = maksymalnaPozadanaWilgotnosc;
    }
    public void sprawdzSensory(){}//?????????????????????
}