Zdefiniuj klasę Mail. Powinna ona dostarczać następujących metod i atrybutów.

* pole message
* typ wyliczeniowy format o wartościach: PLAIN, HTML
* stosowny(e) konstruktor(y)
* gettery dla obu pól
* metodę toString() zwracającą wiadomość w podanym formacie. Na potrzeby zadania umawiamy się, że format HTML różni się od PLAIN tylko tym, że opakowuje treść wiadomości w znaczniki html i body.

Zdefiniuj klasę Attachment. Powinna ona dostarczać następujących metod i atrybutów.

* pole filename, określające nazwę pliku
* pole size, określające rozmiar pliku
* stosowny konstruktor
* gettery dla obu pól
* metodę toString() zwracającą nazwę pliku oraz jego rozmiar. 
  
Rozszerz klasę Mail o możliwość obsługi listy załączników.

Dodatkowo, rozbuduj klasę Mail o następujące metody i atrybuty:

* stała statyczna MAX_MAIL_SIZE określająca maksymalny rozmiar (w bajtach) wiadomości
* metoda addAttachment (zwraca false, jeśli przekroczono maksymalny rozmiar wiadomości)
* metoda getAttachment zwracającą załącznik o podanym numerze
* metoda removeAttachment podajemy nazwę pliku, który chcemy usunąć z listy.
