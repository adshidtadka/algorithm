#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int r[200001];

int main() {
    cin >> n;
    rep(i, n) cin >> r[i];

    int cur = 999999999;
    int maxProfit = -999999999;
    r[n] = 999999999;

    for (int i = 0; i <= n; i++) {
        maxProfit = max(maxProfit, r[i] - cur);
        if (r[i] < cur) cur = r[i];
    }
    cout << maxProfit << endl;
    return 0;
}
