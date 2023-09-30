import javax.swing.text.html.HTML;
import java.io.*;
import java.lang.String;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.lang.*;
import java.util.*;


/////////////////////////////////////////////////////////////////
    class Mail{

    private String message;
    private Type type;
    private static int  MAX_MAIL_SIZE = 1024;

    public Mail(String message, Type type){   //konstruktor
        this.message = message;
        this.type = type;
    }

    enum Type{ PLAIN, HTML }

    public String getMessage() {   //getter dla message
        return message;
    }

    @Override
    public String toString(){                 //toString dla HTML/PLAIN
        if(type == Type.PLAIN){
            return message;
        }
        return "<html><body>" + message + "</html></body>";
    }

    public boolean addAttachment (String str){        //false - jezeli sms wiecej niz 1024 bajtow
        int count = 0;
        for(int i = 0; i < str.length(); i++) { //liczy ile znakow w stringie
            count++;
        }
        if ( count * 2 > MAX_MAIL_SIZE ) return false;
        else return true;
    }

    public void getAttachment(int numer){
        try {
            switch (numer) {
                case 1:
                    BufferedReader file1 = new BufferedReader(new FileReader("SMS1.html")); //duzy sms
                    String line1 = file1.readLine();
                    System.out.println(line1);
                    break;
                case 2:
                    BufferedReader file2 = new BufferedReader(new FileReader("SMS2.plain")); //duzy sms
                    String line2 = file2.readLine();
                    System.out.println(line2);
                    break;
                case 3:
                    BufferedReader file3 = new BufferedReader(new FileReader("SMS3.html")); //duzy sms
                    String line3 = file3.readLine();
                    System.out.println(line3);
                    break;
            }
        }
        catch (IOException e){
            System.out.println("Error" + e );
        }
    }

    public void removeAttachment(int numer1, ArrayList<File> SMSList){
                SMSList.remove(numer1);
    }

}
/////////////////////////////////////////////////////////////////
class Attachment{
    private String filename;
    private int size;

    public Attachment ( String nazwafailu, int rozmiar ){  //konstruktor
        filename = nazwafailu;
        size = rozmiar;
    }

    public String getFilename() {   //getter dla filenamu
        return filename;
    }

    public int getSize() {          //getter dla rozmiaru
        return size;
    }

    public String toString() {
        System.out.println(filename + " " + size);
        return "";
    }
}
/////////////////////////////////////////////////////////////////

public class Main {
    public static void main(String[] args) {

//          Attachment cos1 = new Attachment("Java", 20);
//          cos1.getFilename();
//          cos1.getSize();
//          cos1.toString();

       Mail cos = new Mail("Hello", Mail.Type.PLAIN);
       String str = cos.getMessage();
       System.out.println(cos.addAttachment(str)); //true, bo Hello < 1024

        ArrayList<File> SMSList = new ArrayList<File>();
        File file1 = new File("SMS1.html"); //duzy sms
        File file2 = new File("SMS2.plain");
        File file3 = new File("SMS3.html");


        SMSList.add(file1);
        SMSList.add(file2);
        SMSList.add(file3);

        try {
            BufferedReader br1 = new BufferedReader(new FileReader(file1));

            String line1 = br1.readLine();
            System.out.println(cos.addAttachment(line1)); //false powinno, bo jest > niz 1024

            BufferedReader br2 = new BufferedReader(new FileReader(file2));

            String line2 = br2.readLine();
            System.out.println(cos.addAttachment(line2)); //true powinno

            BufferedReader br3 = new BufferedReader(new FileReader(file3));

            String line3 = br3.readLine();
            System.out.println(cos.addAttachment(line3)); //true powinno

            Scanner scan = new Scanner(System.in);
            System.out.println("Write number (ot 1 do 3), to see this file: ");
            int numer = scan.nextInt();
            cos.getAttachment(numer);

            System.out.println("========================");
            for (int i = 0; i < 3; i++) {
                System.out.println(SMSList.get(i));
            }
            System.out.println("========================");

            System.out.println("Write number (ot 0 do 2), to remove this file from list: ");
            int numer1 = scan.nextInt();
            cos.removeAttachment(numer1,  SMSList);

            System.out.println("========================");
            for (int i = 0; i < 2; i++) {
                System.out.println(SMSList.get(i));
            }
            System.out.println("========================");

        } catch (IOException e) {
            System.out.println("Error" + e);
        }
    }
}
