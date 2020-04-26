#include <iostream>

using namespace std;

int n, m;
int M;
int a[1001];
int dp[1001][1001];

void solve() {
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j - i - a[i] >= 0) {
                dp[i + 1][j + 1] =
                    dp[i + 1][j] + dp[i][j + 1] - dp[i][j - i - a[i]];
            } else {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> M;
    solve();
    return 0;
}
