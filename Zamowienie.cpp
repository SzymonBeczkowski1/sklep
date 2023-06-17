#include "Zamowienie.h"
#include "Sklep.h"
#include "Produkt.h"


Zamowienie::Zamowienie(Produkt produkt, int iloscSztuk, string dataZamowienia) {
    this->produkt = produkt;
    this->iloscSztuk = iloscSztuk;
    this->dataZamowienia = dataZamowienia;
    //this->sposobPlatnosciZamowienia = sposobPlatnosciZamowienia;

}
