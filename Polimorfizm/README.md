##### <a name="Headers"></a> System oceniania testów

Zakładamy, że każde pytanie ma pewną, ale nieznaną w czasie kompilacji liczbę możliwych odpowiedzi, np. N. Obiekt klasy przechowuje pojedynczy rekord z danymi ze skanera. Są to odpowiedzi zaznaczone przez zdającego egzamin. Zaprojektuj klasę Pytanie. Powinna się ona składać z:
* typu wyliczeniowego Odpowiedzi z wartościami BAD_MARKED, BAD_UNMARKED, OK_MARKED, OK_UNMARKED
* kolekcji udzielonych odpowiedzi na pytanie (np. tablica odpowiedzi)
* metody zwracające ilość poprawnych, błędnych i pustych odpowiedzi
* gettery odpowiedzi

Liczba punktów, króre można uzyskać za pojedyncze pytanie zależy od przyjętych zasad oceniania. Test może być jednokrotnego lub wielokrotnego wyboru, z punktacją ujemną lub bez.

Zaprojektuj i zaimplementuj dwie przykładowe klasy oceniające pytania testowe, na przykład:

* OceniaczPojedynczyWybor - 1pkt jeśli zaznaczono tylko jedno pole i była to poprawna odpowiedź, 0pkt w przeciwnym razie
* OceniaczWielokrotnyWybor \
 2pkt jeśli zaznaczono wszystkie dobre odpowiedzi i żadnej złej \
 1pkt jeśli zaznaczono chociaż jedną poprawną odpowiedź, ale nie wszystkie poprawne oraz nie zaznaczono złej odpowiedzi \
 0pkt jeśli nie zaznaczono żadnej odpowiedzi \
 -1pkt jeśli zaznaczono chociaż jedną złą odpowiedź. 
  
* Wyodrębnij klasę podstawową Oceniacz dla dwóch powyższych klas.

Zdefiniuj klasę o nazwie Test. Klasa ta powinna dostarczać następujących właściwości i metod:

* właściwość - zbiór pytań testowych
* właściwość - osoba egzaminowana (potrzebna będzie dodatkowa mała klasa)
* gettery i settery poszczególnych pytań
* getter dla osoby egzaminowanej.

  Test ma dostarczać metodę int ocen(Oceniacz &o), która zwraca sumaryczną liczbę punktów względem podanego oceniacza.
