#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 50000;
const int MAX_E = 50000;
const int MAX_R = 50000;

// union find
// --------------------------------------------
int par[MAX_N];
int depth[MAX_N];

void init_union_find(int n) {
    for (int i = 0; i < n; i++) {
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
    if (x == y) return;

    if (depth[x] < depth[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (depth[x] == depth[y]) depth[x]++;
    }
}

bool same(int x, int y) { return find(x) == find(y); }

struct edge {
    int u, v, cost;
};

bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }

edge es[MAX_E];

int V, E;

int kruskal() {
    sort(es, es + E, comp);
    init_union_find(V);
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int n, m, r;
int x[MAX_R], y[MAX_R], d[MAX_R];

void solve() {
    V = n + m;
    E = r;
    for (int i = 0; i < r; i++) {
        es[i] = (edge){x[i], n + y[i], -d[i]};
    }
    cout << 10000 * V + kruskal() << endl;
}

int main(int argc, char const* argv[]) {
    cin >> n >> m >> r;
    for (int i = 0; i < r; i++) {
        cin >> x[i] >> y[i] >> d[i];
    }
    solve();
    return 0;
}
