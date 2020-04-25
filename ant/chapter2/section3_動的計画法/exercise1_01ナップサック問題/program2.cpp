#include <iostream>
using namespace std;

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];
// dp[i+1][j]: i番目までの品物から重さの総和がj以下となるように選んだ時の,
// 価値の総和の最大値
int dp[MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }

    printf("max sum value is %d\n", dp[n][W]);

    return 0;
}
