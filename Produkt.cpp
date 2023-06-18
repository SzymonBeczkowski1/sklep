#include "Produkt.h"


Produkt::Produkt(string nazwaProduktu, float cenaSztuki, float stawkaVAT, int ilosc) {
    this->nazwaProduktu = nazwaProduktu;
    this->cenaSztuki = cenaSztuki;
    this->stawkaVAT = stawkaVAT;
    this->ilosc = ilosc;
}

Produkt::Produkt() {

}

