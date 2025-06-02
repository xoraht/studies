#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

template <typename T>
class Tablica {
    T* dane;
    size_t rozmiar;
    size_t pojemnosc;
public:
    Tablica(size_t poczatkowa_pojemnosc = 100) : rozmiar(0), pojemnosc(poczatkowa_pojemnosc) {
        dane = new T[pojemnosc];
    }
    ~Tablica() {
        delete[] dane;
    }
    void dodaj_na_koniec(const T& wartosc) {
        if (rozmiar >= pojemnosc) {
            pojemnosc *= 2;
            T* nowe_dane = new T[pojemnosc];
            for (size_t i = 0; i < rozmiar; ++i)
                nowe_dane[i] = dane[i];
            delete[] dane;
            dane = nowe_dane;
        }
        dane[rozmiar++] = wartosc;
    }
    T& operator[](size_t indeks) {
        return dane[indeks];
    }
    const T& operator[](size_t indeks) const {
        return dane[indeks];
    }
    size_t zwroc_rozmiar() const {
        return rozmiar;
    }
};

template <typename T>
void wypisz_min_max(const Tablica<T>& tab) {
    if (tab.zwroc_rozmiar() == 0) return;
    T min = tab[0], max = tab[0];
    for (size_t i = 1; i < tab.zwroc_rozmiar(); ++i) {
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
    }
    cout << "Min = " << min << " Max = " << max << endl;
}

template <>
void wypisz_min_max(const Tablica<double>& tab) {
    if (tab.zwroc_rozmiar() == 0) return;
    double min = tab[0], max = tab[0];
    for (size_t i = 1; i < tab.zwroc_rozmiar(); ++i) {
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
    }
    cout << fixed << setprecision(1);
    cout << "Min = " << min << " Max = " << max << endl;
}

int main() {
    char typ;
    cin >> typ;
    cin.ignore(1);
    if (typ == 'i') {
        Tablica<int> tab;
        char operacja;
        while (cin >> operacja) {
            if (operacja == '+') {
                int wartosc;
                cin >> wartosc;
                tab.dodaj_na_koniec(wartosc);
            } else if (operacja == '-') {
                wypisz_min_max(tab);
            }
        }
    } else if (typ == 'd') {
        Tablica<double> tab;
        char operacja;
        while (cin >> operacja) {
            if (operacja == '+') {
                double wartosc;
                cin >> wartosc;
                tab.dodaj_na_koniec(wartosc);
            } else if (operacja == '-') {
                wypisz_min_max(tab);
            }
        }
    }

    return 0;
}