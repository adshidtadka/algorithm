#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
int M;

int dp[MAX_M + 1][MAX_N + 1];

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    cin >> M;

    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[m][n] % M);
    return 0;
}
