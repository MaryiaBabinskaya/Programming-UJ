//Maryia Babinskaya
package zadanie4.sensory;
public class SensorNiedostepny
        extends java.lang.Exception{
    String sms;
    public SensorNiedostepny(){
        sms = "";
    }
    public SensorNiedostepny(java.lang.String message){
        sms = message;
    }
}