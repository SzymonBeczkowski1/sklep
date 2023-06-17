#include <fstream>
#include "Sklep.h"
#include "Klient.h"
#include "Produkt.h"


using namespace std;


void Sklep::odczytProduktowZPliku() {
    ifstream plik;
    plik.open("produkty.txt", ios_base::in);

    string nazwa;
    float cena;
    float stawkaVAT;
    int ilosc;

    if (plik.is_open()) {
        while (!plik.eof()) {
            plik >> nazwa >> cena >> stawkaVAT >> ilosc;
            if (plik.eof()) break;
            produkty.push_back(Produkt(nazwa, cena, stawkaVAT, ilosc));

        }
    }
    plik.close();

}

void Sklep::wyswietlDostepneProdukty() {
    cout << "---Dostepne produkty---" << endl;
    for (Produkt &produkt: produkty) {
        cout << "Nazwa: " << produkt.nazwaProduktu << endl;
        cout << "Cena: " << produkt.cenaSztuki << "PLN" << endl;
        cout << "Stawka VAT: " << produkt.stawkaVAT << "%" << endl;
        cout << endl;
    }
}

void Sklep::dodajKlienta(Klient klient) {
    klienci.push_back(klient);
}

void Sklep::dodajZamowienie(Zamowienie zamowienie) {
    zamowienia.push_back(zamowienie);
}

Klient Sklep::znajdzKlienta(string imie, string nazwisko) {
    for (Klient &klient: klienci) {
        if (klient.imie == imie && klient.nazwisko == nazwisko)
            return klient;
    }
}

void Sklep::ZapiszKlientowDoPlikuTxt() {
    ofstream plik;
    plik.open("klienci.txt", ios_base::out);

    for (Klient &klient: klienci) {
        plik << klient.imie << " " << klient.nazwisko << " " << klient.adres << " " << klient.plecToStr() << endl;
    }
    plik.close();
}

void Sklep::ZapiszKlientowDoPlikuBinarnego() {
    ofstream plik;
    plik.open("klienci.bin", ios_base::out|ios_base::binary);


    for (Klient &klient: klienci) {
        //plik.write(klient.imie, sizeof(klient.imie));
    }
    plik.close();
}
