#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class StrukturaDanych {
public:
    virtual void dodaj(int element) = 0;
    virtual int usun() = 0;
    virtual ~StrukturaDanych() {}
};

class Stos : public StrukturaDanych {
    stack<int> stos;
public:
    void dodaj(int element) override {
        stos.push(element);
    }
    int usun() override {
        int szczyt = stos.top();
        stos.pop();
        return szczyt;
    }
};

class Kolejka : public StrukturaDanych {
    queue<int> kolejka;
public:
    void dodaj(int element) override {
        kolejka.push(element);
    }
    int usun() override {
        int przod = kolejka.front();
        kolejka.pop();
        return przod;
    }
};

class KolejkaPriorytetowa : public StrukturaDanych {
    priority_queue<int> kolejkaPriorytetowa;
public:
    void dodaj(int element) override {
        kolejkaPriorytetowa.push(element);
    }
    int usun() override {
        int szczyt = kolejkaPriorytetowa.top();
        kolejkaPriorytetowa.pop();
        return szczyt;
    }
};

int main() {
    int liczbaStruktur, liczbaOperacji;
    cin >> liczbaStruktur;
    vector<StrukturaDanych*> struktury(liczbaStruktur);
    for (int i = 0; i < liczbaStruktur; ++i) {
        char typ;
        cin >> typ;
        if (typ == 'S') {
            struktury[i] = new Stos();
        } else if (typ == 'K') {
            struktury[i] = new Kolejka();
        } else if (typ == 'Q') {
            struktury[i] = new KolejkaPriorytetowa();
        }
    }
    cin >> liczbaOperacji;
    for (int i = 0; i < liczbaOperacji; ++i) {
        int numerStruktury;
        char operacja;
        cin >> numerStruktury >> operacja;

        if (operacja == 'D') {
            int element;
            cin >> element;
            struktury[numerStruktury - 1]->dodaj(element);
        } else if (operacja == 'P') {
            cout << struktury[numerStruktury - 1]->usun() << endl;
        }
    }
    for (int i = 0; i < liczbaStruktur; i++) {
        delete struktury[i];
    }
    return 0;
}