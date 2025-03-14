#include <iostream>
#include <ctime>

using namespace std;

class sprawdz_date {
public:
    string jakiDzien(const string& data) {
        int dzien, miesiac, rok;
        if (!sprawdzDate(data, dzien, miesiac, rok) || !czyPoprawna(dzien, miesiac, rok)) {
            return "ERROR";
        }
        tm timeinfo = {};
        timeinfo.tm_mday = dzien;
        timeinfo.tm_mon = miesiac - 1;
        timeinfo.tm_year = rok - 1900;
        mktime(&timeinfo);

    const char* dniTygodnia[] = {"ND", "PN", "WT", "SR", "CZ", "PT", "SB"};
    return dniTygodnia[timeinfo.tm_wday];
}
private:
    bool sprawdzDate(const string& dateStr, int& dzien, int& miesiac, int& rok) {
        if (sscanf(dateStr.c_str(), "%d-%d-%d", &dzien, &miesiac, &rok) != 3 || rok < 0) {
            return false;
        }
        return true;
    }

    bool czyPoprawna(int dzien, int miesiac, int rok) {
        if (rok < 1 || miesiac < 1 || miesiac > 12 || dzien < 1) {
            return false;
        }

        int dniWMiesiacu[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDni = dniWMiesiacu[miesiac - 1];

        if (miesiac == 2 && czyPrzestepny(rok)) {
            maxDni = 29;
        }

        return dzien <= maxDni;
    }

    bool czyPrzestepny(int rok) {
        return (rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0);
    }
    
};

int main() {
    sprawdz_date d;
    string s;
    while (getline(cin, s)) {
        cout << d.jakiDzien(s) << endl;
    }
    return 0;
}