#ifndef SKLEP_PRODUKT_H
#define SKLEP_PRODUKT_H

#include "string"

using namespace std;

class Produkt {
public:
    string nazwaProduktu;
    float cenaSztuki;
    float stawkaVAT;
    int ilosc;

    Produkt(string nazwaProduktu, float cenaSztuki, float stawkaVAT, int ilosc);

    Produkt();


};


#endif //SKLEP_PRODUKT_H
