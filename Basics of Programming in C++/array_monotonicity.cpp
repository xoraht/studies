#include <iostream>

using namespace std;

/// Funkcja wypisuje monotonicznosc tablicy
/// tzn. rosnaca, nierosnaca, malejaca, niemalejaca
/// niemonotoniczna
void monotonicznosc(int tab[], int rozmiar);

int main() {
    int tab1[5] = {1, 2, 3, 4, 5};
    monotonicznosc(tab1, 5); /// rosnaca, niemalejaca

    int tab2[5] = {5, 4, 3, 2, 1};
    monotonicznosc(tab2, 5); /// malejaca, nierosnaca

    int tab3[5] = {5, 5, 3, 2, 1};
    monotonicznosc(tab3, 5); /// nierosnaca

    int tab4[5] = {1, 2, 3, 3, 5};
    monotonicznosc(tab4, 5); /// niemalejaca

    int tab5[5] = {1, 2, 2, 1, 0};
    monotonicznosc(tab5, 5); /// niemonotoniczna

    return 0;
}

void monotonicznosc(int tab[], int rozmiar) {
    bool rosnaca = true;
    bool nierosnaca = true;
    bool malejaca = true;
    bool niemalejaca = true;

    for (int i = 0; i < rozmiar - 1; i++) {
        if (tab[i] == tab[i + 1]) {
            rosnaca = false;
            malejaca = false;
        }
        else if (tab[i] > tab[i + 1]) {
            rosnaca = false;
            niemalejaca = false;
        }
        else if (tab[i] < tab[i + 1]) {
            malejaca = false;
            nierosnaca = false;
        }
    }
    
    for(int i = 0; i < rozmiar; i++) { cout << tab[i] << " "; }
    cout << endl;
    if (rosnaca) cout << "rosnaca" << endl;
    if (niemalejaca) cout << "niemalejaca" << endl;
    if (malejaca) cout << "malejaca" << endl;
    if (nierosnaca) cout << "nierosnaca" << endl;
    if (!rosnaca && !niemalejaca && !malejaca && !nierosnaca) cout << "niemonotoniczna" << endl;
    cout << "-----------" << endl;
}