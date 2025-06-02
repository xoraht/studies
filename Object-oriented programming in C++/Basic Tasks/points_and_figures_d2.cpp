#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Figura {
public:
    virtual bool zawiera(int px, int py) const = 0;
    virtual ~Figura() {}
};

class Kolo : public Figura {
    int x, y, r;
public:
    Kolo(int cx, int cy, int promien) : x(cx), y(cy), r(promien) {}
    bool zawiera(int px, int py) const override {
        return (px - x) * (px - x) + (py - y) * (py - y) <= r * r;
    }
};

class Prostokat : public Figura {
    int x1, y1, x3, y3;
public:
    Prostokat(int lx, int ly, int rx, int ry) : x1(lx), y1(ly), x3(rx), y3(ry) {}
    bool zawiera(int px, int py) const override {
        return px >= x1 && px <= x3 && py >= y1 && py <= y3;
    }
};

int main() {
    int liczbaFigur;
    cin >> liczbaFigur;
    vector<Figura*> figury;

    for (int i = 0; i < liczbaFigur; i++) {
        char typ;
        cin >> typ;
        if (typ == 'o') {
            int x, y, r;
            cin >> x >> y >> r;
            figury.push_back(new Kolo(x, y, r));
        } else if (typ == 'p' || typ == 'k') {
            int x1, y1, x2, y2, x3, y3, x4, y4;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            figury.push_back(new Prostokat(x1, y1, x3, y3));
        }
    }

    int liczbaZapytan;
    cin >> liczbaZapytan;

    for (int i = 0; i < liczbaZapytan; i++) {
        int px, py;
        cin >> px >> py;
        vector<int> wyniki;
        for (int j = 0; j < figury.size(); j++) {
            if (figury[j]->zawiera(px, py)) {
                wyniki.push_back(j);
            }
        }
        sort(wyniki.begin(), wyniki.end());
        for (int indeks : wyniki) {
            cout << indeks << " ";
        }
        cout << endl;
    }
    for (Figura* figura : figury) {
        delete figura;
    }
    return 0;
}