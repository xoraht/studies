#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int per[n];
    int arr[n];
    int perArr[n];


    for (int i = 0; i < n; i++) {
        cin >> per[i];
        per[i] -= 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        perArr[per[i]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << perArr[i] << " ";
    }
    cout << endl;

    return 0;
}
