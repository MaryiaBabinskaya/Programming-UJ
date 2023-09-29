Celem tego zadania będzie napisanie uproszczonego sterowania mikroklimatem w budynku (mieszkaniu).

Sterowanie zbiera dane z sensorów (czujników), analizuje je i ustawia parametry działania urządzeń (efektorów), takich jak kocioł ogrzewania czy wentylator.
##### <a name="Headers"></a> Pakiet efektory
* SterownikKotla (umożliwia ustawienie temperatury wody w centralnym ogrzewaniu)
* SterownikWentylatora (umożliwia tylko włączenie i wyłączenie bez regulacji obrotów)
##### <a name="Headers"></a> Pakiet sensory
Sensory będą pracowały w trybie ``powiadamiania''. Dokładniej, jeśli wskazanie sensora się zmieni, to mają one powiadomić sterowanie mikroklimatem o tej zmianie. 
* Zegar - ustawiony z zewnątrz, proszę nie używać zegara systemowego.
* Termometr - do sterowania mikroklimatem w pomieszczeniu będziemy używać dwóch pomiarów temperatury - na zewnątrz domu oraz wewnętrz pomieszczenia.
* Wilgotnościomierz - (higrometr) czujnik odczytu wilgotności wewnętrz pomieszczenia.
