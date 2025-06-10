#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> kaprekarNumbers;
bool isKaprekar(int n) {
    if (n == 1) return true;
    long long sq = (long long)n * n;
    string str = to_string(sq);
    int len = str.length();
    for (int i = 1; i < len; i++) {
        string left = str.substr(0, i);
        string right = str.substr(i);
        int l = stoi(left);
        int r = stoi(right);
        if (r > 0 && l + r == n) return true;
    }
    return false;
}
void kaprekarNumber() {
    for (int i = 1; i <= 40000; i++) {
        if (isKaprekar(i)) kaprekarNumbers.push_back(i);
    }
}
int main() {
    int T;
    cin >> T;
    kaprekarNumber();
    for (int i = 1; i <= T; i++) {
        int low, high;
        cin >> low >> high;
        cout << "case #" << i << endl;
        bool found = false;
        for (int j : kaprekarNumbers) {
            if (j >= low && j <= high) {
                cout << j << endl;
                found = true;
            } else if (j > high) break;
        }
        if (!found) cout << "no kaprekar numbers" << endl;
        cout << endl;
    }
    return 0;
}