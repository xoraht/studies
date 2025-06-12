#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int dx[5] = {0, 0, 1, -1, 0};
const int dy[5] = {1, -1, 0, 0, 0};

int main() {
    string moves;
    int caseNum = 1;
    while (getline(cin, moves)) {
        int board[3][3];
        memset(board, 0, sizeof(board));
        for (char ch : moves) {
            if (ch < 'a' || ch > 'i') continue;
            int idx = ch - 'a';
            int x = idx / 3;
            int y = idx % 3;
            for (int d = 0; d < 5; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                    board[nx][ny] = (board[nx][ny] + 1) % 10;
                }
            }
        }
        cout << "Case #" << caseNum++ << ":\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}