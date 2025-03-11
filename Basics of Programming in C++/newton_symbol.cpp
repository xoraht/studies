#include <iostream>
using namespace std;

int newtonSymbol(int n, int k);

int main() {
    int n, k;
    cout << "Podaj dwie liczby naturalne n i k (n >= k): ";
    cin >> n >> k;
    if (n < k) {
        cout << "Liczba n musi byc wieksza lub rowna k!" << endl;
        return 1;
    }
    int wynik = newtonSymbol(n, k);
    cout << "Symbol Newtona (" << n << " nad " << k << ") = " << wynik << endl;
    return 0;
}

int newtonSymbol(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return newtonSymbol(n - 1, k - 1) + newtonSymbol(n - 1, k);
}