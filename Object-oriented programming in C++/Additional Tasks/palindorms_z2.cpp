#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool czy_palindrom(const string &liczba) {
    return liczba == string(liczba.rbegin(), liczba.rend());
}

string odwroc_i_dodaj(const string &liczba, int podstawa) {
    string odwrotna_liczba = string(liczba.rbegin(), liczba.rend());
    int przeniesienie = 0, suma;
    string wynik = "";

    for (size_t i = 0; i < liczba.size(); ++i) {
        suma = (isdigit(liczba[i]) ? liczba[i] - '0' : liczba[i] - 'A' + 10) +
               (isdigit(odwrotna_liczba[i]) ? odwrotna_liczba[i] - '0' : odwrotna_liczba[i] - 'A' + 10) + przeniesienie;
        przeniesienie = suma / podstawa;
        suma %= podstawa;
        wynik += (suma < 10) ? char(suma + '0') : char(suma - 10 + 'A');
    }
    if (przeniesienie > 0) {
        wynik += (przeniesienie < 10) ? char(przeniesienie + '0') : char(przeniesienie - 10 + 'A');
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

bool czy_poprawna_w_danej_podstawie(const string &liczba, int podstawa) {
    for (char znak : liczba) {
        int wartosc = (isdigit(znak) ? znak - '0' : znak - 'A' + 10);
        if (wartosc >= podstawa) return false;
    }
    return true;
}

int kroki_do_palindromu(string liczba, int podstawa) {
    if (!czy_poprawna_w_danej_podstawie(liczba, podstawa)) return -1;

    for (int krok = 0; krok < 100; ++krok) {
        if (czy_palindrom(liczba)) return krok;
        liczba = odwroc_i_dodaj(liczba, podstawa);
    }
    return -1;
}

int main() {
    string wejscie;
    while (getline(cin, wejscie)) {
        for (int podstawa = 15; podstawa >= 2; --podstawa) {
            int kroki = kroki_do_palindromu(wejscie, podstawa);
            if (kroki == -1) cout << "? ";
            else cout << kroki << " ";
        }
        cout << endl;
    }
    return 0;
}