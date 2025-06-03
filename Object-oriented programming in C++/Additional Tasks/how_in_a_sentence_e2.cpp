#include <iostream>
#include <algorithm>
using namespace std;

string poprawTekst(string& tekst, bool& czyPierwszyZnak) {
    string wynik;
    bool noweZdanie = false;
    bool ostatniaSpacja = false;

    for (int i = 0; i < tekst.size(); ++i) {
        if (czyPierwszyZnak && isalpha(tekst[i])) {
            wynik += toupper(tekst[i]);
            czyPierwszyZnak = false;
        } 
        else if (noweZdanie && tekst[i] == ' ') {
            wynik += tekst[i]; 
        } 
        else if (noweZdanie && isalpha(tekst[i])) {
            wynik += toupper(tekst[i]);
            noweZdanie = false;
        } 
        else if (tekst[i] == ' ') {
            if(!ostatniaSpacja) {
                wynik += tekst[i];
                ostatniaSpacja = true;
            }
        }
        else {
            wynik += tolower(tekst[i]);
            ostatniaSpacja = false;
        }
        if (tekst[i] == '.' || tekst[i] == '!' || tekst[i] == '?') {
            noweZdanie = true;
        }
    }
    return wynik;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    bool czyPierwszyZnak = true;
    for (int i = 0; i < n; ++i) {
        string linia;
        getline(cin, linia);
        cout << poprawTekst(linia, czyPierwszyZnak) << endl;
    }
    return 0;
}