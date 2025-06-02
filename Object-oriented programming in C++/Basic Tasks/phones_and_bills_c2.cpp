#include <iostream>
#include <string>
using namespace std;

int obliczCzasTrwania(const string& start, const string& koniec) {
    int godzinaStart = stoi(start.substr(0, 2));
    int minutaStart = stoi(start.substr(3, 2));
    int godzinaKoniec = stoi(koniec.substr(0, 2));
    int minutaKoniec = stoi(koniec.substr(3, 2));
    int startWMinutach = godzinaStart * 60 + minutaStart;
    int koniecWMinutach = godzinaKoniec * 60 + minutaKoniec;
    if (koniecWMinutach < startWMinutach) {
        koniecWMinutach += 24 * 60;
    }
    return koniecWMinutach - startWMinutach;
}

int main() {
    string numerAbonenta;
    double stawkaLokalna, stawkaKrajowa, stawkaMiedzynarodowa;
    cin >> numerAbonenta;
    cin >> stawkaLokalna >> stawkaKrajowa >> stawkaMiedzynarodowa;
    cin.ignore();
    string linia;
    double calkowityKoszt = 0.0;

    while (true) {
        getline(cin, linia);
        if (linia.empty()) break;

        size_t pierwszaSpacja = linia.find(' ');
        size_t drugaSpacja = linia.find(' ', pierwszaSpacja + 1);

        string numerPolaczenia = linia.substr(0, pierwszaSpacja);
        string czasStart = linia.substr(pierwszaSpacja + 1, drugaSpacja - pierwszaSpacja - 1);
        string czasKoniec = linia.substr(drugaSpacja + 1);

        double stawka;
        if (numerPolaczenia.substr(0, 2) == numerAbonenta.substr(0, 2)) {
            if (numerPolaczenia.substr(2, 2) == numerAbonenta.substr(2, 2)) {
                stawka = stawkaLokalna;
            } else {
                stawka = stawkaKrajowa;
            }
        } else {
            stawka = stawkaMiedzynarodowa;
        }
        int czasTrwania = obliczCzasTrwania(czasStart, czasKoniec);
        calkowityKoszt += czasTrwania * stawka;
    }

    cout.precision(2);
    cout << fixed << calkowityKoszt << endl;

    return 0;
}