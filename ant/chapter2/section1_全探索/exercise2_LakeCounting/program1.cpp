#include <cmath>
#include <iostream>
using namespace std;

int n, m;
char field[110][110];

void dfs(int x, int y) {
    //置き換える
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

void solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }
    solve();
    return 0;
}