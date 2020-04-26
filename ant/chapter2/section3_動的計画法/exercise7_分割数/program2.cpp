#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int M;
int dp[1001][1001];

void solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = dp[i][j - i] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << dp[m][n] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> M;
    solve();
    return 0;
}
