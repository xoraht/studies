#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool czySzesnastkowy(string tekst) {
    return tekst.size() > 2 && tekst[0] == '0' && tekst[1] == 'x';
}

string doSzesnastkowego(int wartoscDziesietna) {
    stringstream strumien;
    strumien << "0x" << uppercase << hex << wartoscDziesietna;
    return strumien.str();
}

int doDziesietnego(string wartoscSzesnastkowa) {
    int wartoscDziesietna;
    stringstream strumien;
    strumien << hex << wartoscSzesnastkowa.substr(2);
    strumien >> wartoscDziesietna;
    return wartoscDziesietna;
}

int main() {
    string liczba;
    while (true) {
        cin >> liczba;
        if (liczba == "-1") {
            break;
        }
        if (czySzesnastkowy(liczba)) {
            cout << doDziesietnego(liczba) << endl;
        } else {
            cout << doSzesnastkowego(stoi(liczba)) << endl;
        }
    }
    return 0;
}