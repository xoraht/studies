#include <iostream>
using namespace std;

int main() {
    int liczba;
    int odwroconaLiczba = 0;
    cin >> liczba;

    char* bajty = reinterpret_cast<char*>(&liczba);
    char* odwroconeBajty = reinterpret_cast<char*>(&odwroconaLiczba);
    for (int i = 0; i < 4; i++) {
        odwroconeBajty[i] = bajty[3 - i];
    }
    cout << odwroconaLiczba << endl;
    return 0;
}