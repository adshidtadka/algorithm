#include <iostream>

using namespace std;

int n, wMax;
int w[101], v[101];
int dp[101][10001];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wMax; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
            cout << dp[i + 1][j] << ",";
        }
        cout << endl;
    }
    cout << dp[n][wMax] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> wMax;
    solve();
    return 0;
}
