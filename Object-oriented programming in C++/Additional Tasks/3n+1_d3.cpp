#include <iostream>
#include <algorithm>
using namespace std;

int algorytm(int n) {
    int dlugosc = 1;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        dlugosc++; 
    }
    return dlugosc;
}

int main() {
    int N, M;
    cin >> N >> M;
    if (N > M) {
        swap(N, M);
    }
    int maksymalnaDlugosc = 0;
    for (int i = N; i <= M; i++) {
        maksymalnaDlugosc = max(maksymalnaDlugosc, algorytm(i));
    }
    cout << maksymalnaDlugosc;
    return 0;
}