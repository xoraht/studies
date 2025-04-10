#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Kino {
public:
    int rzedy, kolumny;
    map<pair<int, int>, bool> uchwyty;
    map<int, vector<int>> rezerwacje;
    Kino(int r, int c) : rzedy(r), kolumny(c) {}
    void zajmij(const string& miejsce, char znak) {
        int rzad = miejsce[0] - 'A';
        int kolumna = stoi(miejsce.substr(1));
        if (znak == '-') {
            uchwyty[make_pair(rzad, kolumna - 1)] = true;
        } else if (znak == '+') {
            uchwyty[make_pair(rzad, kolumna)] = true;
        }
    }

    void zarezerwuj(const string& miejsce) {
        int rzad = miejsce[0] - 'A';
        int kolumna = stoi(miejsce.substr(1));
        rezerwacje[rzad].push_back(kolumna);
    }

    bool przydziel() {
        map<int, vector<int> >::iterator it;
        for (it = rezerwacje.begin(); it != rezerwacje.end(); ++it) {
            int rzad = it->first;
            vector<int>& kolumny = it->second;
            sort(kolumny.begin(), kolumny.end());
            for (size_t i = 0; i < kolumny.size(); ++i) {
                int kolumna = kolumny[i];
                if (!uchwyty[make_pair(rzad, kolumna - 1)]) {
                    uchwyty[make_pair(rzad, kolumna - 1)] = true;
                } else if (!uchwyty[make_pair(rzad, kolumna)]) {
                    uchwyty[make_pair(rzad, kolumna)] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int R, C, P, Z;
    cin >> R >> C;
    Kino kino(R, C);
    cin >> P;
    for (int i = 0; i < P; i++) {
        string miejsce;
        char znak;
        cin >> miejsce >> znak;
        kino.zajmij(miejsce, znak);
    }
    cin >> Z;
    for (int i = 0; i < Z; i++) {
        string miejsce;
        cin >> miejsce;
        kino.zarezerwuj(miejsce);
    }
    cout << (kino.przydziel() ? "TAK" : "NIE") << endl;
    return 0;
}