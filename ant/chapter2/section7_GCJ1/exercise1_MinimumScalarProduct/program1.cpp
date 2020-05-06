#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int v1[1000001], v2[1000001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    sort(v1, v1 + n);
    sort(v2, v2 + n, greater<int>());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += v1[i] * v2[i];
    }
    cout << ans << endl;
    return 0;
}