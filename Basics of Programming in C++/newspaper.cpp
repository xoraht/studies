#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double priceArr[n];
    char nameArr[n];
    for(int i = 0; i < n; i++) {
        cin >> nameArr[i];
        cin >> priceArr[i];
    }
    string word;
    cin >> word;
    double finalPrice = 0;
    for(int i = 0; i < word.length(); i++) {
        for(int j = 0; j < n; j++) {
            if(word[i] == nameArr[j]) {
                finalPrice += priceArr[j];
            }
        }
    }
    cout << finalPrice / 100 << endl;
    return 0;
}