#include <iostream>

using namespace std;

int main() {
    int N, kopy, tuziny, reszta;
    cin >> N;
    kopy = N / 60;
    tuziny = N % 60 / 12;
    reszta = N % 60 % 12;
    cout << kopy << " " << tuziny << " " << reszta << " ";
}