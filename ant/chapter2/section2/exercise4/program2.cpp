#include <iostream>

using namespace std;

int n, r;
int x[1001];

void solve() {
    int ans = 0;
    int covered = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] >= covered) {
            ans++;
            covered = x[i] + r * 2;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    solve();
    return 0;
}
