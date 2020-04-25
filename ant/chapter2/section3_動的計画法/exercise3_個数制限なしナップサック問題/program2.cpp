#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[2][MAX_W + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[(i + 1) & 1][j] = dp[i & 1][j];
            } else {
                dp[(i + 1) & 1][j] =
                    max(dp[i & 1][j], dp[(i + 1) & 1][j - w[i]] + v[i]);
            }
        }
    }

    printf("max sum value is %d\n", dp[n & 1][W]);
    return 0;
}
