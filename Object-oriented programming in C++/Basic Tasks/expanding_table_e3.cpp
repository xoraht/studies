#include <iostream>
using namespace std;

class TablicaDynamiczna {
    private:
        int *tablica;
        int rozmiar;
        int pojemnosc;
        
        void podwoj_pojemnosc() {
            pojemnosc *= 2;
            int* nowaTablica = new int[pojemnosc];
            for (int i = 0; i < rozmiar; i++) {
                nowaTablica[i] = tablica[i];
            }
            delete[] tablica;
            tablica = nowaTablica;
        }
    public:
        TablicaDynamiczna() {
            rozmiar = 0;
            pojemnosc = 100;
            tablica = new int[pojemnosc];
        }
        ~TablicaDynamiczna() {
            delete[] tablica;
        }
        void push_back(int wartosc) {
            if (rozmiar == pojemnosc) {
                podwoj_pojemnosc();
            }
            tablica[rozmiar++] = wartosc;
        }

        int min() {
            int minimalnaWartosc = tablica[0];
            for (int i = 1; i < rozmiar; i++) {
                if (tablica[i] < minimalnaWartosc) {
                    minimalnaWartosc = tablica[i];
                }
            }
            return minimalnaWartosc;
        }
        int max() {
            int maksymalnaWartosc = tablica[0];
            for (int i = 1; i < rozmiar; i++) {
                if (tablica[i] > maksymalnaWartosc) {
                    maksymalnaWartosc = tablica[i];
                }
            }
            return maksymalnaWartosc;
        }
};

int main() {
    TablicaDynamiczna nowa;
    char znak; int liczba;
    while (cin >> znak) {
        if (znak == '+') {
            cin >> liczba; 
            nowa.push_back(liczba);
        } else {
            cout << "Min = " << nowa.min() << " Max = " << nowa.max() << endl;
        }
    }
    return 0;
}