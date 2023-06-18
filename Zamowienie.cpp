#include "Zamowienie.h"
#include "Sklep.h"
#include "Produkt.h"


Zamowienie::Zamowienie(string nazwaProduktu, float cenaSztuki, float stawkaVAT, int ilosc, int iloscSztuk,
                       string dataZamowienia, sposobPlatnosci sposobPlatnosci1) {
    this->nazwaProduktu = nazwaProduktu;
    this->cenaSztuki = cenaSztuki;
    this->stawkaVAT = stawkaVAT;
    this->ilosc = ilosc;

    this->iloscSztuk = iloscSztuk;
    this->dataZamowienia = dataZamowienia;
    this->sposobPlatnosciZamowienia = sposobPlatnosci1;

}
