#include <iostream>

using namespace std;

int main() {
    int n, k;
    int wynik = 0;
    cin >> n >> k;

    for(int i = n; i > 0; i--) {
        if(n % i == 0) {
            if(k) {
                wynik += i;
                k--;
            }
        }
    }
    cout << wynik << endl;

    return 0;
}
