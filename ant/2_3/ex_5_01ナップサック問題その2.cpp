#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_V = 100;
const int INF = 99999999;

int n, W;
int w[MAX_N], v[MAX_N];
// dp[i+1][j]: i番目までの品物から価値の総和がjとなるよう選んだときの,
// 重さの総和の最小値 そのような解が存在しない場合は十分大きな値INF
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

int main() {
    // 入力値の読み込み
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    // 解く
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            if (j < v[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= MAX_N * MAX_V; i++) {
        if (dp[n][i] <= W) {
            res = i;
        }
    }
    printf("max sum value is %d\n", res);

    return 0;
}
