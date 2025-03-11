#include <iostream>
using namespace std;
int main() {
    int a, b, suma = 0;
    cout << "Liczby calkowite z przedzialu [0, 100]." << endl;
    cout << "Podaj przedzial wedlug [a, b]: " << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    if(a < 0 || b > 100) {
        cout << "Dozwolony przedzial liczbowy to [0,100]!" << endl;
    }
    else {//cout << "Wszystkie liczby nieparzyste z przedzialu: " << endl;
        for(int i = a; i <= b; i++) {
            if(i % 2 == 1) {
                suma += i;
                //cout << i << " ";
            }
        }
        cout << endl << "Suma tych liczb nieparzystych wynosi: " << suma << endl;
    }
    return 0;
}
