#include <cmath>
#include <iostream>
using namespace std;

const int v[6] = {1, 5, 10, 50, 100, 500};

int c[6];
int A;

void solve() {
    int ans = 0;
    for (int i = 5; i >= 0; --i) {
        int t = min(A / v[i], c[i]);
        A -= t * v[i];
        ans += t;
    }
    printf("%d\n", ans);
}

int main() {
    for (int i = 0; i < 6; ++i) {
        cin >> c[i];
    }
    cin >> A;
    solve();
    return 0;
}
