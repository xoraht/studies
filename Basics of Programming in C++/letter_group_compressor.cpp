#include <iostream>

using namespace std;

int main()
{
    int n;
    string napis;
    string nowyNapis;
    cin >> n;
    cin >> napis;
    if(napis.length() != n) {
        cout << "Dlugosc napisu jest inna od deklarowanej!";
        return 1;
    }
    for(int i = 0; i < n; i++) {
        int k = i;
        nowyNapis += napis[i];
        while(napis[k] == napis[k + 1]) {
            k++;
            i++;
        }
    }
    cout << nowyNapis << endl;

    return 0;
}
