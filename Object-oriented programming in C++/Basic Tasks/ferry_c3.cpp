#include <iostream>
#include <string>
using namespace std;

class Czas {
private:
    int godziny;
    int minuty;

public:
    Czas() : godziny(0), minuty(0) {}
    Czas(int h, int m) : godziny(h), minuty(m) {}

    void wczytaj(const string& czasStr) {
        size_t pozycjaDwukropka = czasStr.find(':');
        godziny = stoi(czasStr.substr(0, pozycjaDwukropka));
        minuty = stoi(czasStr.substr(pozycjaDwukropka + 1));
    }
    void dodajMinuty(int m) {
        minuty += m;
        godziny += minuty / 60;
        minuty %= 60;
    }
    bool operator<(const Czas& inny) const {
        if (godziny < inny.godziny) return true;
        if (godziny == inny.godziny && minuty < inny.minuty) return true;
        return false;
    }
    bool operator==(const Czas& inny) const {
        return godziny == inny.godziny && minuty == inny.minuty;
    }
    bool operator<=(const Czas& inny) const {
        return *this < inny || *this == inny;
    }
    bool operator>(const Czas& inny) const {
        return !(*this <= inny);
    }
    bool operator>=(const Czas& inny) const {
        return !(*this < inny);
    }

    string naString() const {
        string h = to_string(godziny);
        string m = to_string(minuty);
        if (h.size() < 2) h = "0" + h;
        if (m.size() < 2) m = "0" + m;
        return h + ":" + m;
    }
};

class Samochod {
public:
    char brzeg;
    Czas czasPrzyjazdu;
    Czas czasWyjazdu;
    Samochod(char b, const Czas& czas) : brzeg(b), czasPrzyjazdu(czas) {}
};

class Prom {
private:
    int pojemnosc;
    Samochod** kolejkaLewyBrzeg;
    Samochod** kolejkaPrawyBrzeg;
    int liczbaLewy;
    int liczbaPrawy;
    int rozmiarLewy;
    int rozmiarPrawy;
    Czas aktualnyCzas;
    char aktualnyBrzeg;

    void powiekszKolejkeLewy() {
        int nowyRozmiar = rozmiarLewy * 2;
        Samochod** nowaKolejka = new Samochod*[nowyRozmiar];
        for (int i = 0; i < liczbaLewy; i++) {
            nowaKolejka[i] = kolejkaLewyBrzeg[i];
        }
        delete[] kolejkaLewyBrzeg;
        kolejkaLewyBrzeg = nowaKolejka;
        rozmiarLewy = nowyRozmiar;
    }

    void powiekszKolejkePrawy() {
        int nowyRozmiar = rozmiarPrawy * 2;
        Samochod** nowaKolejka = new Samochod*[nowyRozmiar];
        for (int i = 0; i < liczbaPrawy; i++) {
            nowaKolejka[i] = kolejkaPrawyBrzeg[i];
        }
        delete[] kolejkaPrawyBrzeg;
        kolejkaPrawyBrzeg = nowaKolejka;
        rozmiarPrawy = nowyRozmiar;
    }

public:
    Prom(int poj) : pojemnosc(poj), aktualnyBrzeg('L'), aktualnyCzas(0, 0) {
        kolejkaLewyBrzeg = new Samochod*[10];
        kolejkaPrawyBrzeg = new Samochod*[10];
        rozmiarLewy = rozmiarPrawy = 10;
        liczbaLewy = liczbaPrawy = 0;
    }

    ~Prom() {
        for (int i = 0; i < liczbaLewy; i++) delete kolejkaLewyBrzeg[i];
        for (int i = 0; i < liczbaPrawy; i++) delete kolejkaPrawyBrzeg[i];
        delete[] kolejkaLewyBrzeg;
        delete[] kolejkaPrawyBrzeg;
    }

    void dodajSamochod(char brzeg, const Czas& czasPrzyjazdu) {
        Samochod* samochod = new Samochod(brzeg, czasPrzyjazdu);
        if (brzeg == 'L') {
            if (liczbaLewy >= rozmiarLewy) powiekszKolejkeLewy();
            kolejkaLewyBrzeg[liczbaLewy++] = samochod;
        } else {
            if (liczbaPrawy >= rozmiarPrawy) powiekszKolejkePrawy();
            kolejkaPrawyBrzeg[liczbaPrawy++] = samochod;
        }
    }

    void przeprowadzSymulacje() {
        aktualnyBrzeg = 'L';
        aktualnyCzas = Czas(0, 0);

        while (liczbaLewy > 0 || liczbaPrawy > 0) {
            if (aktualnyBrzeg == 'L' && liczbaLewy >= pojemnosc) {
                przetworzBrzeg(kolejkaLewyBrzeg, liczbaLewy, 5, "lewego");
            } else if (aktualnyBrzeg == 'P' && liczbaPrawy >= pojemnosc) {
                przetworzBrzeg(kolejkaPrawyBrzeg, liczbaPrawy, 7, "prawego");
            } else {
                Czas nastepnyLewy = (liczbaLewy >= pojemnosc) ? kolejkaLewyBrzeg[pojemnosc - 1]->czasPrzyjazdu : Czas(23, 59);
                Czas nastepnyPrawy = (liczbaPrawy >= pojemnosc) ? kolejkaPrawyBrzeg[pojemnosc - 1]->czasPrzyjazdu : Czas(23, 59);

                if (nastepnyLewy < nastepnyPrawy) {
                    if (aktualnyBrzeg == 'P') {
                        aktualnyCzas.dodajMinuty(7);
                        aktualnyBrzeg = 'L';
                    }
                    przetworzBrzeg(kolejkaLewyBrzeg, liczbaLewy, 5, "lewego");
                } else {
                    if (aktualnyBrzeg == 'L') {
                        aktualnyCzas.dodajMinuty(5);
                        aktualnyBrzeg = 'P';
                    }
                    przetworzBrzeg(kolejkaPrawyBrzeg, liczbaPrawy, 7, "prawego");
                }
            }
        }
    }

private:
    void przetworzBrzeg(Samochod** &kolejka, int &liczba, int czasPodrozy, const string& nazwaBrzegu) {
        int liczbaDoZabrania = min(pojemnosc, liczba);

        Czas czasOdplywu = aktualnyCzas;
        if (liczbaDoZabrania > 0) {
            Czas czasOstatniego = kolejka[liczbaDoZabrania - 1]->czasPrzyjazdu;
            if (czasOstatniego > aktualnyCzas) {
                czasOdplywu = czasOstatniego;
            }
        }

        cout << "Prom odchodzi o godzinie " << czasOdplywu.naString() << " z " << nazwaBrzegu << " brzegu.\n";

        Czas czasPrzybycia = czasOdplywu;
        czasPrzybycia.dodajMinuty(czasPodrozy);

        for (int i = 0; i < liczbaDoZabrania; i++) {
            Samochod* samochod = kolejka[i];
            cout << "Samochod przyjechal o " << samochod->czasPrzyjazdu.naString()
                 << " i wyjechal o " << czasPrzybycia.naString() << ".\n";
            delete samochod;
        }

        for (int i = liczbaDoZabrania; i < liczba; i++) {
            kolejka[i - liczbaDoZabrania] = kolejka[i];
        }

        liczba -= liczbaDoZabrania;
        aktualnyCzas = czasPrzybycia;
        aktualnyBrzeg = (aktualnyBrzeg == 'L') ? 'P' : 'L';
    }
};

int main() {
    int pojemnosc;
    cin >> pojemnosc;
    cin.ignore();

    Prom prom(pojemnosc);
    string linia;

    while (true) {
        getline(cin, linia);
        if (linia.empty()) {
            break;
        }
        char brzeg = linia[0];
        string czasStr = linia.substr(2);
        Czas czas;
        czas.wczytaj(czasStr);
        prom.dodajSamochod(brzeg, czas);
    }
    prom.przeprowadzSymulacje();
    return 0;
}