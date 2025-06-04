#include <iostream>
using namespace std;

int obliczWynik(string test) {
    int wynik = 0;
    int aktualnyCiag = 1;
    for (char znak : test) {
        if (znak == 'O') {
            wynik += aktualnyCiag;
            aktualnyCiag++;
        } else aktualnyCiag = 1;
    }
    return wynik;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string test;
        getline(cin, test);
        int wynik = obliczWynik(test);
        cout << wynik << endl;
    }
    return 0;
}