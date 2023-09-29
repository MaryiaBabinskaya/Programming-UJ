##### <a name="Headers"></a>  Zadanie: Operacje morfologiczne
Trójwymiarowym obrazem binarnym (lub krótko bitmapą) będziemy określać taki obraz trójwymiarowy, w którym każdy piksel ma kolor albo czarny, albo biały. W rozpoznawaniu i analizie obrazów binarnych bardzo często stosuje się tak zwane operacje (filtry) morfologiczne. Standardowo filtry te są zdefiniowane bardzo ogólnie. My, na potrzeby niniejszego zadania, zawęzimy nieco ich definicje. \
Sąsiadem piksela p jest każdy inny piksel bitmapy, który styka się z nim pełną ścianą. Piksele stykające się tylko wierzchołkami lub krawędziami nie są sąsiadami. Na przykład, w bitmapie o rozmiarze 7x7x7 indeksowanej od zera, piksel p=(3,3,3) ma dokładnie sześciu sąsiadów: \
(2,3,3), (4,3,3), (3,2,3), (3,4,3), (3,3,2), (3,3,4). \
Jeżeli piksel leży na brzegu bitmapy, to sąsiedztwo zawężamy do pikseli, które są w bitmapie. \
Poniżej omówimy kolejno filtry morfologiczne, które będą musieli zaimplementować: 
##### <a name="Headers"></a> Inwersja
lub prościej negacja - polega na zamianie pikseli czarnych na białe i białych na czarne.
##### <a name="Headers"></a> Erozja
przez piksel brzegowy obrazu rozumiemy piksel czarny, którego jednym z sąsiadów jest piksel biały. Operacja erozji polega na tym, że najpierw lokalizowane są wszystkie piksele brzegowe w danym obrazie, a następnie ich kolor jest ustawiany na biały.
##### <a name="Headers"></a> Dylatacja
jest w pewnym sensie operacją odwrotną do erozji. W wyniku dylatacji wszystkie białe piksele, które sąsiadują z pikselem czarnym, mają zmieniony kolor na czarny.
##### <a name="Headers"></a> Zerowanie
wszystkie piksele ustawiane są na kolor biały
##### <a name="Headers"></a> Uśrednianie
dla każdego piksela p obrazu sprawdzamy liczbę sąsiadujących z nim pikseli białych i czarnych. Jeśli ma on więcej niż trzech sąsiadów w kolorze k, to nowym kolorem piksela p jest kolor k. W przeciwnym razie kolor piksela nie zmienia się.
