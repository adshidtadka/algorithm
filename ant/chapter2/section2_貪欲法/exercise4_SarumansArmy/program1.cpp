#include <cmath>
#include <iostream>
using namespace std;

int n, r;
int x[1010];

void solve() {
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x, x + n);

    int i = 0, ans = 0;
    while (i < n) {
        int s = x[i++];
        while (i < n && x[i] <= s + r) {
            i++;
        }

        int p = x[i - 1];
        while (i < n && x[i] <= p + r) {
            i++;
        }
        ans++;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}