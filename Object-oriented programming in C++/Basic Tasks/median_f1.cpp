#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMedianInt(vector<int>& data) {
    sort(data.begin(), data.end());
    int n = data.size();
    if (n % 2 == 1) {
        return data[n / 2];
    } else {
        return (data[n / 2 - 1] + data[n / 2]) / 2;
    }
}

double calculateMedianDouble(vector<double>& data) {
    sort(data.begin(), data.end());
    int n = data.size();
    if (n % 2 == 1) {
        return data[n / 2];
    } else {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }
}

int main() {
    char typ; int n;
    cin >> typ >> n;
    if (typ == 'i') {
        vector<int> data(n);
        for (int i = 0; i < n; ++i) cin >> data[i];

        double mediana = calculateMedianInt(data);
        cout << mediana << endl;
    } 
    else if (typ == 'd') {
        vector<double> data(n);
        for (int i = 0; i < n; ++i) cin >> data[i];
        double mediana = calculateMedianDouble(data);
        cout << mediana << endl;
    }
    return 0;
}