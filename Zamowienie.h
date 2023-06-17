#ifndef SKLEP_ZAMOWIENIE_H
#define SKLEP_ZAMOWIENIE_H

#include "string"
#include "Produkt.h"

using namespace std;

enum sposobPlatnosci {
    blik,
    przelew,
    zaPobraniem

};

class Zamowienie{
public:

    Produkt produkt;
    int iloscSztuk;
    string dataZamowienia;
    sposobPlatnosci sposobPlatnosciZamowienia;

    Zamowienie(Produkt produkt, int iloscSztuk, string dataZamowienia);

};


#endif //SKLEP_ZAMOWIENIE_H
