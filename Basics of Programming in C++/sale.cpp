#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Ile butelek mleka chcesz zakupic od Wlodzimira? Zakres n[1, 200]" << endl;
    cout << "n = ";
    cin >> n;
    int suma = n;
    if(n < 1 || n > 200) {
        cout << "Dozwolony przedzial liczbowy to [1, 200]!" << endl;
    }
    else {
        while(n >= 2) {
            n = n -= 2;
            suma += 1;
        }
        cout << "Maksymalna liczba butelek mleka, ktora mozemy wypic wynosi: " << suma << endl;
    }
    return 0;
}
