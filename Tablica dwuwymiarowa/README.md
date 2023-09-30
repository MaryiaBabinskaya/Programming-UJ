Napisz program, który utworzy tablicę dwuwymiarową (nieregularnych kształtów), wypełni ją liczbami całkowitymi takimi, że liczba dziesiątek tej liczby będzie równa indeksowi wiersza tej tablicy w której się znajduje, natomiast liczba jedności będzie równa indeksowi kolumny w której się znajduje. Program będzie realizował realokację pamięci dla tablicy dwuwymiarowej. Dla podanych w programie punktów (minr,minc) oraz (maxr,maxc) oznaczających odpowiednio lewy górny róg i prawy dolny róg prostokąta, pod którymi dane z tablicy zostaną "usunięte". Prostokąt ten wyznacza obszar do zredukowania w tablicy dwuwymiarowej. 

Jeżeli w wierszu wartości pokrywają się z wyznaczonym prostokątem, a za tymi wartościami znajdują się jeszcze inne, to należy te dodatkowe wartości przesunąć do lewej strony (zaczynając od miejsca, w którym wartości zaczynają się pokrywać z obszarem wyznaczonym przez prostokąt). W przypadku, kiedy cały wiersz znajduje się pod obszarem wyznaczonym przez prostokąt, należy również zredukować cały wiersz, a następujące po nim wiersze przesunąć odpowiednio do góry. 

W wyniku opisanych redukcji tablica dwuwymiarowa powinna dopasować ilość zaangażowanej pamięci do nowej jej postaci. Na końcu program powinien prawidłowo zwolnić pozostałą pamięć. Program powinien wyświetlić na standardowym wyjściu najpierw oryginalną tablicę dwuwymiarową (w czytelnym formacie), później współrzędne punktów prostokąta, a następnie tablicę po redukcji (również w czytelnym formacie) - por. przykład. Proszę, żeby punkty wyznaczające prostokąt do redukcji miały nazwy zmiennych takie jak w treści w celu łatwiejszego ich zlokalizowania przy testowaniu (jeżeli ktoś użył innych zmiennych, proszę na początku programu zrobić przypisanie moja_zmienna_minimalny_wiersz = minr; moja_zmienna_minimalna_kolumna = minc; itd.).  

Do rozwiązania należy użyć funkcji do zarządzania pamięcią typowych dla języka C, tzn. funkcji malloc(), realloc() i free() (z pliku nagłówkowego cstdlib). Program powinien być udostępniony w jednym pliku źródłowym .cpp, kompilującym się kompilatorem zgodnym ze standardem C++11. Do testowania Państwa aplikacji będę korzystał z programu valgrind, więc proszę też pamiętać o testowaniu wycieków pamięci, niedozwolonych przeglądów tablicy poza jej zakresem, podwójnych zwolnień itp. 

Przykład:

 0  1  2  3 \
10 11 12 13 14 \
20 \
30 31 32 33 34 35 36 \
40 41 \
50 51 52 53 54 \
60 61 62 63 64 

(1,0) - (5,2)

 0  1  2  3 \
13 14 \
33 34 35 36 \
53 54 \
60 61 62 63 64
