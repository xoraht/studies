#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    int punkty;

public:
    Student() : imie(""), nazwisko(""), punkty(0) {}
    void wczytaj() {
        cin >> imie >> nazwisko >> punkty;
    }
    void wypisz() const {
        cout << imie << " " << nazwisko << " " << punkty << endl;
    }
    int getPunkty() const {
        return punkty;
    }
    friend bool porownaj(const Student& a, const Student& b);
};

bool porownaj(const Student& a, const Student& b) {
    if (a.punkty != b.punkty)
        return a.punkty > b.punkty;
    if (a.nazwisko != b.nazwisko)
        return a.nazwisko < b.nazwisko;
    return a.imie < b.imie;
}

int main() {
    int N;
    cin >> N;
    Student* wszyscy = new Student[N];
    Student* zakwalifikowani = new Student[N];
    int liczbaZakwalifikowanych = 0;
    for (int i = 0; i < N; i++) {
        wszyscy[i].wczytaj();
    }
    int prog;
    cin >> prog;
    for (int i = 0; i < N; i++) {
        if (wszyscy[i].getPunkty() >= prog) {
            zakwalifikowani[liczbaZakwalifikowanych++] = wszyscy[i];
        }
    }
    sort(zakwalifikowani, zakwalifikowani + liczbaZakwalifikowanych, porownaj);
    for (int i = 0; i < liczbaZakwalifikowanych; i++) {
        zakwalifikowani[i].wypisz();
    }
    delete[] wszyscy;
    delete[] zakwalifikowani;
    return 0;
}