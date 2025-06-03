#include <iostream>
using namespace std;

string jakiTypLiczby(int liczba) {
    int sumaDzielnikow = 0;
    for (int i = 1; i <= liczba / 2; i++) {
        if (liczba % i == 0) {
            sumaDzielnikow += i;
        }
    }
    if(sumaDzielnikow == liczba) {
        return "doskonala";
    }
    else if(sumaDzielnikow < liczba) {
        return "nadmiarowa";
    }
    else return "deficytowa";
}

int main() {
    int N;
    cin >> N;
    if(N >= 1000) return 1;
    for(int i = 0; i < N; i++) {
        int liczba;
        cin >> liczba;
        if(liczba > 32000) return 1;
        if(liczba == 0) {cout << "0 - liczba deficytowa" << endl;}
        else cout << liczba << " - liczba " << jakiTypLiczby(liczba) << endl;
    }
    return 0;
}