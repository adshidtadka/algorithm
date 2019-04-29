#include <iostream>
using namespace std;

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

// i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j) {
    int res;
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }

    if (i == n) {
        // 品物なし
        res = 0;
    } else if (j < w[i]) {
        // 次の品物が入らない
        res = rec(i + 1, j);
    } else {
        // 入れない場合と入れる場合を両方ためす
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
}

int main() {
    // まだ調べていないことを表す-1でメモ化テーブルを初期化
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    printf("max sum value is %d\n", rec(0, W));

    return 0;
}
