#include <iostream>

using namespace std;

int main() {
    int n;
    int wynik = 0, licznik = 0;
    string liczba;
    cin >> liczba;
    for(int i : liczba) {
        if(liczba.length() % 2 == 0) {
            licznik++;
        }
        if(licznik % 2 == 0) {
            wynik += i-48;
        }
        licznik++;
    }
    cout << wynik;
    return 0;
}