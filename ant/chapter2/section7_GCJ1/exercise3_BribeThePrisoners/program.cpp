#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int p, q;
int a[10001];
int dp[10001][10001];

int main() {
    cin >> p >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[q + 1] = p + 1;
    for (int w = 2; w <= q + 1; w++) {
        for (int i = 0; i <= q - w + 1; i++) {
            int first = a[i + w] - a[i] - w + 1;
            dp[i][i + w] = min(dp[i][i + w - 1], dp[i + 1][i + w]) + first;
        }
    }
    cout << dp[0][q + 1] << endl;
    return 0;
}