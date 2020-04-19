#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 110;
const int INF = 10000000;

typedef pair<int, int> P;

char maze[MAX_N][MAX_N + 1];
int n, m;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_N];

//移動４方向ベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    queue<P> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (maze[nx][ny] == 'G') {
                if (d[nx][ny] == INF) {
                    d[nx][ny] = d[p.first][p.second] + 1;
                }
            }
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maze[nx][ny] == '.') {
                    if (d[nx][ny] == INF) {
                        d[nx][ny] = d[p.first][p.second] + 1;
                        que.push(P(nx, ny));
                    }
                }
            }
        }
    }
    cout << d[gx][gy] << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    solve();
}