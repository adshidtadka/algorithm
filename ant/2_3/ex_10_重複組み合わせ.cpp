#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1000;

int n, m;
int a[MAX_N + 1];
int M;

int dp[MAX_N + 1][MAX_N + 1];

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> M;

    // 1つも選ばない方法は常に1通り
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j - 1 - a[i] >= 0) {
                dp[i + 1][j] =
                    (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            } else {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
