#ifndef SKLEP_SKLEP_H
#define SKLEP_SKLEP_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Produkt.h"
#include "Klient.h"
#include "Zamowienie.h"

using namespace std;



class Sklep {
public:
    vector<Klient> klienci;
    vector<Produkt> produkty;
    vector<Zamowienie> zamowienia;

    void dodajKlienta(Klient klient);
    void dodajZamowienie(Zamowienie zamowienie);
    Klient znajdzKlienta(string imie, string nazwisko);
    void ZapiszKlientowDoPlikuTxt();
    void ZapiszKlientowDoPlikuBinarnego();

    void wyswietlWszystkieZamowieniaIZapiszDoPlikow();


    void odczytProduktowZPliku();
    void wyswietlDostepneProdukty();

};


#endif //SKLEP_SKLEP_H
