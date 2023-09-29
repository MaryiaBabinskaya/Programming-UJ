//Maryia Babinskaya
package zadanie4.wentylacja;
import zadanie4.SprawdzajacySensory;
import zadanie4.efektory.SterownikWentylatora;
public abstract class SterowanieWentylacja
        extends java.lang.Object
        implements SprawdzajacySensory{
    SterownikWentylatora wentylator;
    public SterowanieWentylacja(){}
    public SterownikWentylatora jakiSterownikWentylatora(){
        return wentylator;
    }
    public void ustawSterownikWentylatora(SterownikWentylatora _wentylator){
        wentylator = _wentylator;
    }
}