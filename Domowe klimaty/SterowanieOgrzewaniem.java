//Maryia Babinskaya
package zadanie4.ogrzewanie;
import zadanie4.SprawdzajacySensory;
import zadanie4.efektory.SterownikKotla;
public abstract class SterowanieOgrzewaniem
        extends java.lang.Object
        implements SprawdzajacySensory{
    SterownikKotla sterownikKotla;
    public SterowanieOgrzewaniem(){}
    public SterownikKotla pobierzSterownikKotla(){ return sterownikKotla; }
    public void ustawSterownikPieca(SterownikKotla kociol){ sterownikKotla = kociol; }
}