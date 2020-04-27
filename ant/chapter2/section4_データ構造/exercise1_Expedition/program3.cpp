#include <iostream>
#include <queue>

using namespace std;

int n, l, p;
int a[10001], b[10001];
priority_queue<int> q;

void solve() {
    int pet = p;
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d = a[i] - pos;
        while (pet < d) {
            if (q.empty()) {
                cout << -1 << endl;
                return;
            }
            pet += q.top();
            q.pop();
            ans++;
        }
        pos += d;
        pet -= d;
        q.push(b[i]);
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
