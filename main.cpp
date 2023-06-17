#include <iostream>
#include "Klient.h"
#include "Zamowienie.h"
#include "Sklep.h"

using namespace std;

int main() {
    Sklep sklep;
    sklep.odczytProduktowZPliku();

    bool loop = true;
    int operacja;
    while (loop) {
        cout << "Podaj numer operacji do wykonania";
        cin >> operacja;


        switch (operacja) {

            case 1: {
                string imie, nazwisko, adres, plecSTR;
                plec plec;
                cout << "---Utworz nowy profil klienta---" << endl;
                cout << "Podaj imie:";
                cin >> imie;
                cout << "Podaj nazwisko:";
                cin >> nazwisko;
                cout << "Podaj adres:";
                cin >> adres;
                cout << "Podaj plec (m/k):";
                cin >> plecSTR;
                if (plecSTR == "k") plec = kobieta;
                else plec = mezczyzna;

                Klient klient(imie, nazwisko, adres, plec);
                sklep.dodajKlienta(klient);
                cout << "Klient dodany pomyslnie" << endl;
                break;
            }

            case 2: {
                string imie, nazwisko;
                cout << "---Podaj imie i nazwisko klienta do modyfikacji---" << endl;
                cin >> imie >> nazwisko;
                Klient klient = sklep.znajdzKlienta(imie, nazwisko);

                string noweImie, noweNazwisko, nowyAdres;
                cout << "Podaj nowe imie: ";
                cin >> noweImie;
                cout << "Podaj nowe nazwisko: ";
                cin >> noweNazwisko;
                cout << "Podaj nowy adres: ";
                cin >> nowyAdres;
                klient.modyfikujKlienta(noweImie, noweNazwisko, nowyAdres);
                cout << "Klient zmodyfikowany pomyslnie" << endl;

                break;

            }
            case 3: {
                string typPliku;
                cout << "---Wybierz typ pliku do zapisu klientow (txt/bin)---" << endl;
                cin >> typPliku;
                if (typPliku == "txt") sklep.ZapiszKlientowDoPlikuTxt();
                else if (typPliku == "bin") sklep.ZapiszKlientowDoPlikuBinarnego();
                break;

            }
            case 4: {
                string imie, nazwisko;
                cout << "---Podaj imie i nazwisko klienta ktory dokonuje zakupu---" << endl;
                cin >> imie >> nazwisko;
                Klient klient = sklep.znajdzKlienta(imie, nazwisko);
                //cout << "Klient " << klient.imie << klient.nazwisko << "kupuje";

                string nazwaProduktu, data, platnosc;
                sposobPlatnosci sposobPlatnosci = przelew;
                int zamawianaIlosc;
                cout << "Podaj nazwe produktu:";
                cin >> nazwaProduktu;
                cout << "Podaj ilosc:";
                cin >> zamawianaIlosc;

                cout << "Podaj date:";
                cin >> data;

                cout << "Podaj sposob platnosci: (przelew/pobranie)";
                cin >> platnosc;
                if (platnosc == "przelew") sposobPlatnosci = przelew;
                if (platnosc == "pobranie") sposobPlatnosci = zaPobraniem;


                for (Produkt &produkt: sklep.produkty) {
                    if (nazwaProduktu == produkt.nazwaProduktu && produkt.ilosc > zamawianaIlosc) {
                        produkt.ilosc -= zamawianaIlosc;

                        cout << "znaleziono dobry produkt";

                        klient.zamowieniaKlienta.push_back(Zamowienie(produkt.nazwaProduktu, produkt.cenaSztuki, produkt.stawkaVAT, produkt.ilosc, zamawianaIlosc, data, sposobPlatnosci));
                        //cout << "Zamowienie zrealizowane" << produkt.ilosc << " " << produkt.nazwaProduktu << endl;

                        for (Zamowienie& zamowienie : klient.zamowieniaKlienta) {
                            cout << "Zamowienie: " << zamowienie.nazwaProduktu << " Dnia: " << zamowienie.dataZamowienia << endl;
                        }

                        break;
                    }
                }

                break;

            }

            case 5: {
                //edycja zamowienia
                string imie, nazwisko, nazwaProduktu;
                cout << "---Podaj imie, nazwisko i zamawiany produkt do edycji ---" << endl;
                cin >> imie >> nazwisko >> nazwaProduktu;
                Klient klient = sklep.znajdzKlienta(imie, nazwisko);
                Zamowienie zamowienieDoEdycji = klient.modyfikujZamowienie(nazwaProduktu);

                string sposobPlatnosci, dataZamowienia, platnosc;

                cout << "Podaj sposob platnosci: (przelew/pobranie)";
                cin >> platnosc;
                if (platnosc == "przelew") zamowienieDoEdycji.sposobPlatnosciZamowienia = przelew;
                if (platnosc == "pobranie") zamowienieDoEdycji.sposobPlatnosciZamowienia = zaPobraniem;

                cout << "Podaj dateZamowienia" << endl;
                cin >> dataZamowienia;
                zamowienieDoEdycji.dataZamowienia = dataZamowienia;

                break;
            }
            case 6:

                break;
            case 7:
                sklep.wyswietlDostepneProdukty();

                break;

            case 8: {
                for (Klient &klient: sklep.klienci) {
                    //cout << klient.imie << " " << klient.nazwisko;

                    if (klient.zamowieniaKlienta.empty())
                        cout << "Brak zamówień dla klienta: " << klient.imie << " " << klient.nazwisko << endl;
                    else {
                        for (Zamowienie &zamowienie: klient.zamowieniaKlienta) {
                            cout << "cos";
//                            cout << klient.imie << " " << klient.nazwisko << " zamowil"
//                                 << zamowienie.produkt->nazwaProduktu << " dnia " << zamowienie.dataZamowienia
//                                 << endl;
                        }
                    }


                }
            }

            case 9:
                loop = false;
                break;
            default:
                cout << "Niepoprawny numer operacji" << endl;
                break;
        }

    }

    return 0;
}
