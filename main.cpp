#include <iostream>
#include "Klient.h"
#include "Zamowienie.h"
#include "Sklep.h"

using namespace std;

int main() {
    Sklep sklep;

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

                string nazwaProduktu, data, platnosc;
                int zamawianaIlosc;
                cout << "Podaj nazwe produktu: ";
                cin >> nazwaProduktu;
                cout << "Podaj ilosc: ";
                cin >> zamawianaIlosc;
                data = "13_11_4324";


                for (Produkt& produkt : sklep.produkty) {
                    if (nazwaProduktu == produkt.nazwaProduktu && produkt.ilosc > zamawianaIlosc) {
                        produkt.ilosc -= zamawianaIlosc;
                        //Produkt produkt11("Laptop", 2500.0, 23.0, 4);
                        klient.zamowieniaKlienta.push_back(Zamowienie(produkt, zamawianaIlosc, data));

                        break;
                    }
                }

                break;

            }

            case 5:
                //edycja zamowienia
                break;

            case 6:
                sklep.odczytProduktowZPliku();
                sklep.wyswietlDostepneProdukty();

                break;


            case 7:
                loop = false;
                break;
            default:
                cout << "Niepoprawny numer operacji";
        }

    }

    return 0;
}
