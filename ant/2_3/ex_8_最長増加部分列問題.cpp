#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int INF = 999999;

int n;
int a[MAX_N + 1];

// dp[i]:
// 長さがi+1であるような増加部分列における最終要素の最小値(存在しない場合はINF)
int dp[MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(dp, dp + n, INF);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%ld\n", lower_bound(dp, dp + n, INF) - dp);
    return 0;
}
