#include <cmath>
#include <iostream>
using namespace std;

int n, m;
char position[101][101];

void removeLake(int x, int y) {
    position[x][y] = '.';
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 and i < n and j >= 0 and j < m) {
                if (position[i][j] == 'w') {
                    removeLake(i, j);
                }
            }
        }
    }
}

void solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (position[i][j] == 'w') {
                ans++;
                removeLake(i, j);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> position[i][j];
        }
    }
    solve();
}