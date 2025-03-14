#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tab[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0) tab[i][j] = i+1*j+1;
            else tab[i][j] = tab[0][j]*tab[i][0];
            if(j == n - 1) cout << tab[i][j]
            << " " << endl;
            else cout << tab[i][j] << " " ;
            
        }
    }
    return 0;
}