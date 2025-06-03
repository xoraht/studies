#include <iostream>
using namespace std;

void sms(string message) {
    int licznik[10] = {0};
    for (char ch : message) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        if (ch == 'a' || ch == 'b' || ch == 'c') licznik[2] += (ch - 'a' + 1);
        else if (ch == 'd' || ch == 'e' || ch == 'f') licznik[3] += (ch - 'd' + 1);
        else if (ch == 'g' || ch == 'h' || ch == 'i') licznik[4] += (ch - 'g' + 1);
        else if (ch == 'j' || ch == 'k' || ch == 'l') licznik[5] += (ch - 'j' + 1);
        else if (ch == 'm' || ch == 'n' || ch == 'o') licznik[6] += (ch - 'm' + 1);
        else if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's') licznik[7] += (ch - 'p' + 1);
        else if (ch == 't' || ch == 'u' || ch == 'v') licznik[8] += (ch - 't' + 1);
        else if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z') licznik[9] += (ch - 'w' + 1);
        else if (ch == ' ') licznik[0] += 1;
    }

    for (int i = 2; i <= 10; ++i) {
        if(i == 10) {
            cout << "[" << 0 << "] - " << licznik[0] << endl;
        }
        else if (licznik[i] > 0) {
            cout << "[" << i << "] - " << licznik[i] << endl;
        }
    }
}

int main() {
    string zdanie;
    getline(cin, zdanie);
    sms(zdanie);

    return 0;
}