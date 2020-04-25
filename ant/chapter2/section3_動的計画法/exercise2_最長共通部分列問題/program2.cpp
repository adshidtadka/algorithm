#include <iostream>

using namespace std;

int n, m;
char s[1001], t[1001];
int dp[1001][1001];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << dp[n][m] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    cin >> s >> t;
    solve();
    return 0;
}
