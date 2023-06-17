#ifndef SKLEP_ZAMOWIENIE_H
#define SKLEP_ZAMOWIENIE_H

#include "string"
#include "Produkt.h"

using namespace std;

enum sposobPlatnosci {
    przelew,
    zaPobraniem

};

class Zamowienie : public Produkt{
public:

    Produkt produkt;
    int iloscSztuk;
    string dataZamowienia;
    sposobPlatnosci sposobPlatnosciZamowienia;

    Zamowienie(string nazwaProduktu, float cenaSztuki, float stawkaVAT, int ilosc, int iloscSztuk, string dataZamowienia, sposobPlatnosci sposobPlatnosci1);

};


#endif //SKLEP_ZAMOWIENIE_H
