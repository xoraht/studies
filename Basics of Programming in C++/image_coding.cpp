#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int height, width;
        cin >> height >> width;
        char arr[height][width];
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                cin >> arr[j][k];
            }
        }
        int f[256] = {0};
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                f[arr[j][k]]++;
            }
        }
        int maxF = 0;
        for (int j = 0; j < 256; j++) {
            if (f[j] > maxF) {
                maxF = f[j];
            }
        }
        int sum = 0;
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (f[arr[j][k]] == maxF) {
                    sum += 2;
                } else {
                    sum += 1;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}