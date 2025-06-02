#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Punkt {
    int x, y;
};
int main() {
    int N, M, narciarzX, narciarzY, celX, celY;
    cin >> N >> M;
    vector<vector<int>> mapa(N, vector<int>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> mapa[i][j];
    cin >> narciarzX >> narciarzY >> celX >> celY;
    vector<vector<bool>> odwiedzony(N, vector<bool>(M, false));
    queue<Punkt> q;
    q.push({narciarzX, narciarzY});
    odwiedzony[narciarzX][narciarzY] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool znaleziono = false;
    while (!q.empty()) {
        Punkt p = q.front(); q.pop();
        if (p.x == celX && p.y == celY) {
            znaleziono = true;
            break;
        }
        for(int k=0; k<4; k++) {
            int nx = p.x + dx[k];
            int ny = p.y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                !odwiedzony[nx][ny] &&
                mapa[nx][ny] < mapa[p.x][p.y]) {
                odwiedzony[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    znaleziono ? (cout << "Istnieje zjazd" << endl) : (cout << "Zjazd nie istnieje" << endl);
    return 0;
}