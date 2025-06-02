#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Figura {
public:
    virtual double obwod() const = 0;
    virtual double pole() const = 0;
    virtual ~Figura() = default;
};

class Kolo : public Figura {
    double promien;
public:
    Kolo(double pr) : promien(pr) {}
    double obwod() const override {
        return 2 * PI * promien;
    }
    double pole() const override {
        return PI * promien * promien;
    }
};

class Kwadrat : public Figura {
    double bok;
public:
    Kwadrat(double b) : bok(b) {}
    double obwod() const override {
        return 4 * bok;
    }
    double pole() const override {
        return bok * bok;
    }
};

class Prostokat : public Figura {
    double bok1, bok2;
public:
    Prostokat(double b1, double b2) : bok1(b1), bok2(b2) {}
    double obwod() const override {
        return 2 * (bok1 + bok2);
    }
    double pole() const override {
        return bok1 * bok2;
    }
};

class Trojkat : public Figura {
    double bok1, bok2, bok3;
public:
    Trojkat(double b1, double b2, double b3) : bok1(b1), bok2(b2), bok3(b3) {}
    double obwod() const override {
        return bok1 + bok2 + bok3;
    }
    double pole() const override {
        double s = obwod() / 2;
        return sqrt(s * (s - bok1) * (s - bok2) * (s - bok3));
    }
};

int main() {
    int N, M;
    cin >> N;
    vector<Figura*> figury;
    
    for (int i = 0; i < N; i++) {
        char typ;
        cin >> typ;
        if (typ == 'o') {
            double pr;
            cin >> pr;
            figury.push_back(new Kolo(pr));
        } else if (typ == 'k') {
            double b;
            cin >> b;
            figury.push_back(new Kwadrat(b));
        } else if (typ == 'p') {
            double b1, b2;
            cin >> b1 >> b2;
            figury.push_back(new Prostokat(b1, b2));
        } else if (typ == 't') {
            double b1, b2, b3;
            cin >> b1 >> b2 >> b3;
            figury.push_back(new Trojkat(b1, b2, b3));
        }
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        char zapytanie;
        int idx;
        cin >> zapytanie >> idx;
        cout << fixed << setprecision(2);
        if (zapytanie == 'o') {
            cout << figury[idx - 1]->obwod() << endl;
        } else if (zapytanie == 'p') {
            cout << figury[idx - 1]->pole() << endl;
        }
    }
    
    for (auto figura : figury) {
        delete figura;
    }
    
    return 0;
}