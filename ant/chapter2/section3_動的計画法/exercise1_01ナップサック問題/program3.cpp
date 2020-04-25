#include <iostream>

using namespace std;

int n, w_max;
int w[101], v[101];
int dp[101][10001];

int rec(int index, int w_cap) {
    if (dp[index][w_cap] != -1) {
        return dp[index][w_cap];
    }
    int v_total;
    if (index == n) {
        v_total = 0;
    } else if (w[index] > w_cap) {
        v_total = rec(index + 1, w_cap);
    } else {
        v_total = max(rec(index + 1, w_cap),
                      rec(index + 1, w_cap - w[index]) + v[index]);
    }
    dp[index][w_cap] = v_total;
    return v_total;
}

void solve() { cout << rec(0, w_max) << endl; }

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> w_max;
    memset(dp, -1, sizeof(dp));
    solve();
    return 0;
}
