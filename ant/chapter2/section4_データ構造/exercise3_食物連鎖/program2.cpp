#include <iostream>

using namespace std;

int par[10000];    // 親
int depth[10000];  // 木の深さ

void init(int N) {
    for (int i = 0; i < N; i++) {
        par[i] = i;
        depth[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }

    if (depth[x] < depth[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (depth[x] == depth[y]) {
            depth[x]++;
        }
    }
}

bool same(int x, int y) { return find(x) == find(y); }

int N, K;
int T[100001];
int X[100001], Y[100001];

void solve() {
    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int t = T[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            ans++;
            cout << "i = " << i << ", x = " << x << ", y = " << y << endl;
            continue;
        }
        if (t == 1) {
            if (same(x, y + N) || same(x, y + N * 2)) {
                ans++;
                cout << "i = " << i << ", x = " << x << ", y = " << y << endl;
                continue;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        } else {
            if (same(x, y) || same(x, y + N * 2)) {
                ans++;
                cout << "i = " << i << ", x = " << x << ", y = " << y << endl;
                continue;
            } else {
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + N * 2, y);
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> T[i] >> X[i] >> Y[i];
    }
    solve();
    return 0;
}
