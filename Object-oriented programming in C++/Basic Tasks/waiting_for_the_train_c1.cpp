#include <iostream>
#include <string>
using namespace std;

class Czas {
private:
    int godziny;
    int minuty;
public:
    Czas(int godziny, int minuty) {
        this->godziny = godziny;
        this->minuty = minuty;
    }
    void operator+=(const int &opoznienie) {
        minuty = minuty + opoznienie;
        napraw_czas();
    }
    void wyswietl_godzine() {
        if(godziny <= 9) cout << '0';
        cout << godziny << ':';
        if(minuty <= 9) cout << '0';
        cout << minuty << endl;
    }
    void napraw_czas() {
        while(minuty >= 60) {
            minuty -= 60;
            godziny += 1;
        }
        while(godziny >= 24) godziny -= 24;
    }
    
};

int main() {
    int g, m; char separator; string s;
    cin >> g >> separator >> m;
    cin.ignore();
    if(separator != ':') return 1;
    Czas c(g, m);
    c.wyswietl_godzine();
    while (getline(cin, s)) {
        c += stoi(s);
        c.wyswietl_godzine();
    }
    return 0;
}