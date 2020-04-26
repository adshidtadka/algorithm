#include <iostream>

using namespace std;

int n;
int a[1001];
int dp[1001][1001];

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j + 1] != -1) {
                if (dp[i][j + 1] < a[i]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else {
                    dp[i + 1][j + 1] = a[i];
                }
            } else if (dp[i][j] != -1) {
                if (dp[i][j] < a[i]) {
                    dp[i + 1][j + 1] = a[i];
                }
            } else {
                break;
            }
            cout << dp[i + 1][j + 1] << ",";
        }
        cout << endl;
    }
    for (int j = n; j >= 0; j--) {
        if (dp[n][j] != -1) {
            cout << j << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}
