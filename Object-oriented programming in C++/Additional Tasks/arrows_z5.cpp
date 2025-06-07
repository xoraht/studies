#include <iostream>
#include <string>
using namespace std;

int znajdzNajdluzszaStrzalke(const string& tekst) {
    int maksDlugosc = -1;
    int n = tekst.length();
    for (int i = 0; i < n; i++) {
        if (tekst[i] == '<') {
            int j = i + 1;
            while (j < n && tekst[j] == '-') j++;
            int dlugosc = j - i;
            if (dlugosc >= 1) maksDlugosc = max(maksDlugosc, dlugosc);
            j = i + 1;
            while (j < n && tekst[j] == '=') j++;
            dlugosc = j - i;
            if (dlugosc >= 2) maksDlugosc = max(maksDlugosc, dlugosc);
        }
        if (tekst[i] == '>') {
            maksDlugosc = max(maksDlugosc, 1);
        }
        if (tekst[i] == '-') {
            int j = i;
            while (j < n && tekst[j] == '-') j++;
            if (j < n && tekst[j] == '>') {
                int dlugosc = j - i + 1;
                maksDlugosc = max(maksDlugosc, dlugosc);
            }
        }
        if (tekst[i] == '=') {
            int j = i;
            while (j < n && tekst[j] == '=') j++;
            if (j < n && tekst[j] == '>') {
                int dlugosc = j - i + 1;
                maksDlugosc = max(maksDlugosc, dlugosc);
            }
        }
    }
    return maksDlugosc;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
        string tekst;
        getline(cin, tekst);
        int wynik = znajdzNajdluzszaStrzalke(tekst);
        cout << "Case " << i << ": " << wynik << endl;
    }
    return 0;
}