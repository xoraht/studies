#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

double obliczPromien(double a, double b, double c) {
    double polObwod = (a + b + c) / 2.0;
    if (a <= 0 || b <= 0 || c <= 0 || polObwod <= max({a, b, c})) {
        return 1.0;
    }
    double pole = sqrt(polObwod * (polObwod - a) * (polObwod - b) * (polObwod - c));
    return pole / polObwod;
}

int main() {
    double a, b, c;

    // Wczytywanie trójkątów do obliczenia
    while (cin >> a >> b >> c) {
        double promien = obliczPromien(a, b, c);
        cout << "Promien okraglego stolu wynosi: " << fixed << setprecision(3) << promien << endl;
    }
    return 0;
}