//Maryia Babinskaya
package zadanie4.wentylacja;
import zadanie4.UzywajacyZegara;
import zadanie4.czas.PoraDoby;
import zadanie4.sensory.Zegar;
import java.util.Vector;
import static zadanie4.czas.PrzelicznikCzasu.sekundaDnia;
public class CzasoweSterowanieWentylacja
        extends SterowanieWentylacja
        implements UzywajacyZegara {
    Zegar zegar;
    Vector<PoraDoby> tablica;
    public CzasoweSterowanieWentylacja() {
        tablica = new Vector<>();
    }
    public void ustawZegar(Zegar _zegar) {
        zegar = _zegar;
    }
    public void dodajOkresWlaczenia(PoraDoby okresWlaczenia) {
        tablica.add(okresWlaczenia);
    }
    public PoraDoby[] pobierzOkresyWlaczenia() {
        return tablica.toArray(new PoraDoby[0]);
    }
    public void usunOkresWlaczenia(PoraDoby _okres) {
        tablica.remove(_okres);
    }
    public void sprawdzSensory() {
        int x = sekundaDnia(zegar.pobierzCzas());
        for (PoraDoby okres : tablica) {
            if (okres.zawieraSie(x)) {
                wentylator.ustawWlaczenie(true);
                return;
            }
        }
        wentylator.ustawWlaczenie(false);
    }
}