#include <iostream>
using namespace std;

const int MAX_N = 1000;

int n;
int a[MAX_N + 1];

// dp[i]: 最後がa[i]であるような最長の増加部分列の長さ
int dp[MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    return 0;
}
