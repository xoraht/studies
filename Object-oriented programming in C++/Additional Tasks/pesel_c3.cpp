#include <iostream>
#include <string>
using namespace std;

bool czyPoprawnyPESEL(int pesel[]) {
    int wagi[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += pesel[i] * wagi[i];
    }
    int cyfraKontrolna = (10 - (suma % 10)) % 10;
    return cyfraKontrolna == pesel[10];
}

string pobierzDateUrodzenia(int pesel[]) {
    int rok = pesel[0] * 10 + pesel[1];
    int miesiac = pesel[2] * 10 + pesel[3];
    int dzien = pesel[4] * 10 + pesel[5];

    if (miesiac >= 1 && miesiac <= 12) {
        rok += 1900;
    } else if (miesiac >= 21 && miesiac <= 32) {
        miesiac -= 20;
        rok += 2000;
    } else if (miesiac >= 41 && miesiac <= 52) {
        miesiac -= 40;
        rok += 2100;
    } else if (miesiac >= 61 && miesiac <= 72) {
        miesiac -= 60;
        rok += 2200;
    } else if (miesiac >= 81 && miesiac <= 92) {
        miesiac -= 80;
        rok += 1800;
    } else {
        return "BLAD";
    }
    char dataUrodzenia[11];
    snprintf(dataUrodzenia, sizeof(dataUrodzenia), "%02d-%02d-%04d", dzien, miesiac, rok);
    return string(dataUrodzenia);
}

char pobierzPlec(int pesel[]) {
    return (pesel[9] % 2 == 0) ? 'K' : 'M';
}

int main() {
    string wejscie;
    cin >> wejscie;

    if (wejscie.length() != 11) {
        cout << "BLAD" << endl;
        return 0;
    }

    int pesel[11];
    for (int i = 0; i < 11; i++) {
        pesel[i] = wejscie[i] - '0';
    }

    if (!czyPoprawnyPESEL(pesel)) {
        cout << "BLAD" << endl;
    } else {
        if (pobierzDateUrodzenia(pesel) == "BLAD") {
            cout << "BLAD" << endl;
        } else {
            cout << pobierzDateUrodzenia(pesel) << " " << pobierzPlec(pesel) << endl;
        }
    }

    return 0;
}