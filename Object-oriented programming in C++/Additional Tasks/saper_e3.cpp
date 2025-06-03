#include <iostream>
using namespace std;

int main() {
    int n, m, licznikBomb = 0;
    cin >> n;
    cin >> m;
    char plansza[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> plansza[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (plansza[i][j] == '.') {
                i > 0 && plansza[i-1][j] == '*' && licznikBomb++;
                i < n - 1 && plansza[i+1][j] == '*' && licznikBomb++;
                j > 0 && plansza[i][j-1] == '*' && licznikBomb++;
                j < m - 1 && plansza[i][j+1] == '*' && licznikBomb++;
                i < n - 1 && j < m - 1 && plansza[i+1][j+1] == '*' && licznikBomb++;
                i < n - 1 && j > 0 && plansza[i+1][j-1] == '*' && licznikBomb++;
                i > 0 && j < m - 1 && plansza[i-1][j+1] == '*' && licznikBomb++;
                i > 0 && j > 0 && plansza[i-1][j-1] == '*' && licznikBomb++;
                plansza[i][j] = licznikBomb - 208;
            }
            licznikBomb = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j+1 == m) cout << plansza[i][j] << endl;
            else cout << plansza[i][j];
        }
    }
    return 0;
}