#include <iostream>
#include <vector>
using namespace std;

class Sudoku {
public:
    int N, rozmiar;
    int** plansza;
    bool stan = true;
    Sudoku(int N) {
        this->N = N;
        rozmiar = N * N;
        plansza = new int*[rozmiar];
        for(int i = 0; i < rozmiar; i++) {
            plansza[i] = new int[rozmiar];
        }
    }
    ~Sudoku() {
        for(int i = 0; i < rozmiar; i++) {
            delete[] plansza[i];
        }
        delete[] plansza;
    }
    
    void wprowadz_sudoku() {
        for(int i = 0; i < rozmiar; i++) {
            for(int j = 0; j < rozmiar; j++) {
                cin >> plansza[i][j];
            }
        }
    }
    void wyswietl_sudoku() {
        for(int i = 0; i < rozmiar; i++) {
            for(int j = 0; j < rozmiar; j++) {
                j == rozmiar - 1 ? cout << plansza[i][j] << " " << endl : cout << plansza[i][j] << " ";
            }
        }
    }
    void check_row() {
        for(int i = 0; i < rozmiar; i++) {
            for(int j = 0; j < rozmiar; j++) { 
                for(int k = j + 1; k < rozmiar; k++) {
                    if(plansza[i][j] == plansza[i][k]) stan = false;
                }
            }
        }
    }
    void check_column() {
        for(int i = 0; i < rozmiar; i++) {
            for(int j = 0; j < rozmiar; j++) { 
                for(int k = i + 1; k < rozmiar; k++) {
                    if(plansza[i][j] == plansza[k][j]) stan = false;
                }
            }
        }
    }
    void check_box() {
        for (int row = 0; row < rozmiar; row += N) {
            for (int col = 0; col < rozmiar; col += N) {
                vector<bool> visited(rozmiar + 1, false);
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        int num = plansza[row + i][col + j];
                        if (visited[num]) {
                            stan = false;
                            return;
                        }
                        visited[num] = true;
                    }
                }
            }
        }
    }
};

int main() {
    int rozmiar;
    cin >> rozmiar;
    Sudoku s(rozmiar);
    s.wprowadz_sudoku();
    //s.wyswietl_sudoku();
    s.check_row();
    s.check_column();
    s.check_box();
    cout << (s.stan ? "TAK" : "NIE") << endl;
    return 0;
}