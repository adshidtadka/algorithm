typedef long long ll;

#include <iostream>
#include <queue>

using namespace std;

int n;
int l[10001];
priority_queue<int, vector<int>, greater<int> > q;

void solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        q.push(l[i]);
    }
    while (q.size() > 1) {
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        ans += first + second;
        q.push(first + second);
        cout << "ans = " << ans << endl;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    solve();
    return 0;
}
