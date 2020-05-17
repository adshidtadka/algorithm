#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m;
int a[200001], b[200001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int> > v(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }

    queue<P> q;
    for (int i = 0; i < v[1].size(); i++) {
        q.push(make_pair(1, v[1][i]));
    }

    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    while (!q.empty()) {
        P pos = q.front();
        q.pop();
        if (ans[pos.second] == 0) {
            ans[pos.second] = pos.first;
            for (int i = 0; i < v[pos.second].size(); i++) {
                q.push(make_pair(pos.second, v[pos.second][i]));
            }
            v[pos.second].clear();
            pos.first = pos.second;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (ans[i] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
