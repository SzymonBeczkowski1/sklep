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
        cout << "Dostepna ilosc: " << produkt.ilosc << endl;
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

    string adres, plecSTR;
    plec plec;
    cout << "---Nie znaleziono klient o tym imieniu i nazwisku, dodaj nowego klienta---" << endl;
    cout << "Podaj adres:";
    cin >> adres;
    cout << "Podaj plec (m/k):";
    cin >> plecSTR;
    if (plecSTR == "k") plec = kobieta;
    else plec = mezczyzna;
    Klient klient(imie, nazwisko, adres, plec);
    klienci.push_back(klient);
    cout << "Klient dodany pomyslnie" << endl;
    return klient;
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
    plik.open("klienci.bin", ios_base::out | ios_base::binary);


    for (Klient &klient: klienci) {
        string dane = klient.imie + " " + klient.nazwisko + " " + klient.adres + "\n";
        const char *daneBinarne = dane.c_str();
        plik.write(daneBinarne, dane.size());
    }
    plik.close();
}

void Sklep::wyswietlWszystkieZamowieniaIZapiszDoPlikow() {
    string sposobPlatnosciStr;
    ofstream plik;
    plik.open("zamowienia.txt", ios_base::out);

    ofstream plikBin;
    plikBin.open("zamowienia.bin", ios_base::out | ios_base::binary);


    for (Zamowienie &zamowienie: zamowienia) {
        if (zamowienie.sposobPlatnosciZamowienia == przelew) sposobPlatnosciStr = "przelew";
        else sposobPlatnosciStr = "za pobraniem";

        cout << "Nazwa: " << zamowienie.nazwaProduktu << " Dnia: " << zamowienie.dataZamowienia
             << " Ilosc: " << zamowienie.iloscSztuk << " Stawka VAT: " << zamowienie.stawkaVAT
             << " Sposob platnosci: " << sposobPlatnosciStr << " Koszt: "
             << zamowienie.cenaSztuki * zamowienie.iloscSztuk << endl;

        plik << "Nazwa: " << zamowienie.nazwaProduktu << " Dnia: " << zamowienie.dataZamowienia
             << "Ilosc: " << zamowienie.iloscSztuk << " Stawka VAT: " << zamowienie.stawkaVAT
             << "Sposob platnosci: " << sposobPlatnosciStr << " Koszt: "
             << zamowienie.cenaSztuki * zamowienie.iloscSztuk << endl;


        string dane = "Nazwa: " + zamowienie.nazwaProduktu + "Dnia " + zamowienie.nazwaProduktu + "\n";
        const char *daneBinarne = dane.c_str();
        plikBin.write(daneBinarne, dane.size());


    }


}
