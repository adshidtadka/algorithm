#include <iostream>

using namespace std;

int n;
int a[101], m[101];
int k;
int dp[101][100001];

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] >= 0) {
                dp[i + 1][j] = m[i];
            } else if (j < a[i] || dp[i + 1][j - a[i]] <= 0) {
                dp[i + 1][j] = -1;
            } else {
                dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
            }
            cout << dp[i + 1][j] << ",";
        }
        cout << endl;
    }
    if (dp[n][k] >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    cin >> k;
    solve();
    return 0;
}
