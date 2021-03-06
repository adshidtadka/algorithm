#include <iostream>
#include <queue>

using namespace std;

int n, l, p;
int a[10001], b[10001];
priority_queue<int> q;

void solve() {
    int pos = p;
    int ans = 0;
    while (pos < l) {
        for (int i = 0; i < n; i++) {
            if (a[i] <= pos) {
                q.push(b[i]);
            }
        }
        if (q.empty()) {
            cout << -1 << endl;
            return;
        }
        pos += q.top();
        q.pop();
        ans++;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> l >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve();
    return 0;
}
