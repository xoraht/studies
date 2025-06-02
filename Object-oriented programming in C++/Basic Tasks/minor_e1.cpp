#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    const int MAX_N = 100;
    double matrix[MAX_N][MAX_N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];
    double max_minor = -INFINITY;
    for (int i1 = 0; i1 < N; ++i1) {
        for (int i2 = i1 + 1; i2 < N; ++i2) {
            for (int j1 = 0; j1 < M; ++j1) {
                for (int j2 = j1 + 1; j2 < M; ++j2) {
                    double A = matrix[i1][j1];
                    double B = matrix[i1][j2];
                    double C = matrix[i2][j1];
                    double D = matrix[i2][j2];
                    double det = A * D - B * C;
                    if (det > max_minor)
                        max_minor = det;
                }
            }
        }
    }
    cout.precision(2);
    cout << fixed << max_minor << endl;
    return 0;
}