//Maryia Babinskaya
package zadanie4.sensory;
import zadanie4.SprawdzajacySensory;
import java.util.Vector;
public abstract class SensorObserwowanyImpl
        extends java.lang.Object
        implements SensorObserwowany{
    Vector<SprawdzajacySensory> tablica;
    public SensorObserwowanyImpl(){
        tablica = new Vector<>();
    }
    public void dodajObserwartoraSensorow(SprawdzajacySensory sprawdzajacy){
        tablica.add(sprawdzajacy);
    }
    public void wyczyscObserwatorowSensorow(){}
    protected void powiadom(){
        for (SprawdzajacySensory i : tablica) {
            try {
                i.sprawdzSensory();
            } catch (SensorNiedostepny e) {
                e.printStackTrace();
            }
        }
    }
}