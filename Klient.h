#ifndef SKLEP_KLIENT_H
#define SKLEP_KLIENT_H

#include "string"
#include "Zamowienie.h"
#include <iostream>
#include <vector>

using namespace std;


enum plec {
    kobieta, mezczyzna
};

class Klient {
public:
    string imie;
    string nazwisko;
    string adres;
    plec plecKlienta;

    vector<Zamowienie> zamowieniaKlienta;


    string plecToStr();

    Klient(string imie, string nazwisko, string adres, plec plecKlienta);

    void modyfikujKlienta(string imie, string nazwisko, string adres);

    Zamowienie modyfikujZamowienie(string nazwaProduktu);


};


#endif //SKLEP_KLIENT_H
