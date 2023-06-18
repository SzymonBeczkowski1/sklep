
#include <iostream>
#include "Klient.h"
#include "string"
#include <fstream>

using namespace std;

Klient::Klient(string imie, string nazwisko, string adres, plec plecKlienta) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->adres = adres;
    this->plecKlienta = plecKlienta;
}


string Klient::plecToStr() {
    if (plecKlienta == mezczyzna) return "mezczyzna";
    else return "kobieta";
}

void Klient::modyfikujKlienta(string imie, string nazwisko, string adres) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->adres = adres;
}

Zamowienie Klient::modyfikujZamowienie(string nazwaProduktu) {
    for (Zamowienie &zamowienie: zamowieniaKlienta) {
        if (zamowienie.produkt.nazwaProduktu == nazwaProduktu)
            return zamowienie;
    }
}


