//Maryia Babinskaya
package zadanie4.ogrzewanie;
import zadanie4.sensory.SensorNiedostepny;
import zadanie4.sensory.Termometr;
public class StalotemperaturoweSterowanieOgrzewaniem
extends SterowanieOgrzewaniem{
    double wsp;
    double minTemperatura;
    double docelowaTemperatura;
    Termometr zewnetrznaTemp;
    Termometr wewnetrznaTemp;
    public StalotemperaturoweSterowanieOgrzewaniem(){
        docelowaTemperatura = 0;
        minTemperatura = 0;
        wsp = 0;
    }
    @Override
    public void sprawdzSensory() throws SensorNiedostepny {
            if(wewnetrznaTemp.pobierzTemperature() >= docelowaTemperatura && docelowaTemperatura - zewnetrznaTemp.pobierzTemperature() < minTemperatura) sterownikKotla.ustawZadanaTemperature((int) sterownikKotla.pobierzMinimalnaTemperatureWlaczenia() - 28);
            else if(wewnetrznaTemp.pobierzTemperature() < docelowaTemperatura && docelowaTemperatura - zewnetrznaTemp.pobierzTemperature() < minTemperatura) sterownikKotla.ustawZadanaTemperature(((int) ((docelowaTemperatura - wewnetrznaTemp.pobierzTemperature())*wsp))+sterownikKotla.pobierzMinimalnaTemperatureWlaczenia());
            else sterownikKotla.ustawZadanaTemperature(((int)((docelowaTemperatura-zewnetrznaTemp.pobierzTemperature()-minTemperatura)*wsp)) + sterownikKotla.pobierzMinimalnaTemperatureWlaczenia());
    }
    public Termometr pobierzTermometrZewnetrzny(){
        return zewnetrznaTemp;
    }
    public void ustawTermometrZewnetrzny(Termometr termometrZewnetrzny){
        zewnetrznaTemp = termometrZewnetrzny;
    }
    public Termometr pobierzTermometrWewnetrzny(){
        return wewnetrznaTemp;
    }
    public void ustawTermometrWewnetrzny(Termometr termometrWewnetrzny){
        wewnetrznaTemp = termometrWewnetrzny;
    }
    public double pobierzDocelowaTemperatura(){
        return docelowaTemperatura;
    }
    public void ustawDocelowaTemperatura(double minimalnaTemperatura){
        docelowaTemperatura = minimalnaTemperatura;
    }
    public double pobierzMinimalnaRoznica(){
     return minTemperatura;
    }
    public void ustawMinimalnaRoznica(double minimalnaRoznica){
        minTemperatura = minimalnaRoznica;
    }
    public double pobierzWspolczynnik(){
        return wsp;
    }
    public void ustawWspolczynnik(double wspolczynnik){
        wsp = wspolczynnik;
    }
}