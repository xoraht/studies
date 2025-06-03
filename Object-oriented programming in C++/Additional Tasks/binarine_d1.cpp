#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string binarna = "";
    int licznik = 0;
    if (N == 0) {
        binarna = "0";
    } else {
        while (N > 0) {
            int bit = N % 2;       
            if (bit == 1) licznik++; 
            binarna = char(bit + '0') + binarna; 
            N /= 2;
        }
    }
    cout << binarna << " " << licznik << endl;
    return 0;
}