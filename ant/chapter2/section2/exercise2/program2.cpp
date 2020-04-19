#include <cmath>
#include <iostream>
using namespace std;

const int MAX_N = 100000;

int n, s[MAX_N], t[MAX_N];

pair<int, int> itv[MAX_N];

void solve() {
    for (int i = 0; i < n; i++) {
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv + n);

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    solve();
    return 0;
}
