#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_K = 100000;

int n;
int K;
int a[MAX_N];
int m[MAX_N];
// dp[i+1][j]: i番目まででjを作る際に余る最大のi番目の個数(作れない場合は-1)
int dp[MAX_K];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> m[i];
    }
    cin >> K;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] < 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }

    if (dp[K] > 0) {
        printf("answer is YES\n");
    } else {
        printf("answer is NO\n");
    }

    return 0;
}
