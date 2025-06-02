#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string liczba;
    while (cin >> liczba && liczba != "0") {
        cout << "Original number was " << liczba << endl;
        vector<string> lancuch;
        string obecna = liczba;
        while (find(lancuch.begin(), lancuch.end(), obecna) == lancuch.end()) {
            lancuch.push_back(obecna);
            string rosnaco = obecna, malejaco = obecna;
            sort(rosnaco.begin(), rosnaco.end());
            sort(malejaco.rbegin(), malejaco.rend());
            string rosnaco_do_wypisania = rosnaco;
            rosnaco_do_wypisania.erase(0, rosnaco_do_wypisania.find_first_not_of('0'));
            if (rosnaco_do_wypisania.empty()) rosnaco_do_wypisania = "0";
            int x = stoi(malejaco), y = stoi(rosnaco), wynik = x - y;
            string wynik_str = to_string(wynik);
            if (wynik_str != "0") {
                while (wynik_str.length() < liczba.length())
                    wynik_str = "0" + wynik_str;
            }
            cout << malejaco << " - " << rosnaco_do_wypisania << " = " << wynik_str << endl;
            obecna = wynik_str;
        }
        cout << "Chain length " << lancuch.size() << endl << endl;
    }
    return 0;
}