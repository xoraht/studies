#include <iostream>
using namespace std;

class Antyzegar {
private:
    int godziny;
    int minuty;
public:
    Antyzegar(int godziny, int minuty) {
        if(godziny == 12) {
            this->godziny = 12;
        } else {
            this->godziny = 12 - godziny;
        }
        this->minuty = (60 - minuty) % 60;
        if (this->minuty != 0) {
            this->godziny = (this->godziny - 1 + 12) % 12;
            if (this->godziny == 0) this->godziny = 12;
        }
    }
    void wyswietl_godzine() {
        if(godziny < 10) cout << '0';
        cout << godziny << ':';
        if(minuty < 10) cout << '0';
        cout << minuty << endl;
    }
};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int g, m; char separator;
        cin >> g >> separator >> m;
        Antyzegar zegar(g, m);
        zegar.wyswietl_godzine();
    }
    return 0;
}
