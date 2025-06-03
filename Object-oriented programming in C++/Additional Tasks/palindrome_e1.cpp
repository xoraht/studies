#include <iostream>
#include <algorithm>
using namespace std;

bool czyPalindrom(string wyraz) {
    string nowyWyraz = wyraz;
    reverse(wyraz.begin(), wyraz.end());
    if(wyraz == nowyWyraz) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string wyraz;
        cin >> wyraz;
        cout << wyraz << " - to" << (czyPalindrom(wyraz) ? "" : " nie") << " jest palindrom" << endl;
    }
    return 0;
}