#include <iostream>

using namespace std;

int n, wMax;
int vMax = 0;
int w[101], v[101];
int dp[101][10001];

void solve() {
    fill(dp[0], dp[0] + n * vMax + 1, 10001);
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n * vMax; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
            cout << dp[i + 1][j] << ",";
        }
        cout << endl;
    }
    for (int j = n * vMax; j >= 0; j--) {
        if (dp[n][j] <= wMax) {
            cout << j << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        vMax = max(v[i], vMax);
    }
    cin >> wMax;
    solve();
    return 0;
}
