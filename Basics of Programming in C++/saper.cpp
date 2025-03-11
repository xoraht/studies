#include <iostream>

using namespace std;

int main() {
    // INICJACJA I DEKLARACJA ZMIENNYCH
    int n, licznikBomb = 0;
    cin >> n;
    char plansza[n][n];

    // POBIERANIE PLANSZY OD UZYTKOWNIKA
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> plansza[i][j];
        }
    }

    // ZMIENIANIE POLA NA CYFRE
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (plansza[i][j] == 'P') {
                plansza[i-1][j] == 'M' && licznikBomb++;
                plansza[i+1][j] == 'M' && licznikBomb++;
                plansza[i][j-1] == 'M' && licznikBomb++;
                plansza[i][j+1] == 'M' && licznikBomb++;
                plansza[i+1][j+1] == 'M' && licznikBomb++;
                plansza[i+1][j-1] == 'M' && licznikBomb++;
                plansza[i-1][j+1] == 'M' && licznikBomb++;
                plansza[i-1][j-1] == 'M' && licznikBomb++;
                plansza[i][j] = licznikBomb - 208;
            }
            licznikBomb = 0;
        }
    }
    // DRUKOWANIE PLANSZY
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j+1 == n) {
                cout << plansza[i][j] << " " << endl;
            }
            else cout << plansza[i][j] << " ";
        }
    }
    return 0;
}