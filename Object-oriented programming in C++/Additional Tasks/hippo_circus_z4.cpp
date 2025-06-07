#include <iostream>
#include <algorithm>
using namespace std;

class HippoCircus {
private:
    int N;
    int H;
    int Ta;
    int Td;
    int* heights;

public:
    HippoCircus(int n, int h, int ta, int td, int* hts) 
        : N(n), H(h), Ta(ta), Td(td), heights(new int[n]) {
        for (int i = 0; i < n; i++) {
            heights[i] = hts[i];
        }
        sort(heights, heights + N);
    }
    ~HippoCircus() {
        delete[] heights;
    }

    long long calculateMinTime() {
        long long totalTime = 0;
        int left = 0;
        int right = N - 1;
        if (Td >= 2 * Ta) {
            return N * Ta;
        }
        while (left <= right) {
            if (left == right) {
                totalTime += Ta;
                break;
            }
            if (heights[left] + heights[right] < H) {
                totalTime += Td;
                left++;
                right--;
            } else {
                totalTime += Ta;
                right--;
            }
        }
        return totalTime;
    }
};

int main() {
    int C;
    cin >> C;
    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;
        int* heights = new int[N];
        for (int i = 0; i < N; i++) cin >> heights[i];
        HippoCircus circus(N, H, Ta, Td, heights);
        long long minTime = circus.calculateMinTime();
        cout << "Case " << caseNum << ": " << minTime << endl;
        delete[] heights;
    }
    return 0;
}