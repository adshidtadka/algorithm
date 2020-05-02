#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int n, r;

struct edge {
    int to, cost;
};

vector<edge> g[5001];

int dist1[5001];
int dist2[5001];

const int INF = 99999999;

void solve() {
    for (int i = 0; i < n; i++) {
        dist1[i] = INF;
        dist2[i] = INF;
    }
    priority_queue<P, vector<P>, greater<P> > q;
    dist1[0] = 0;
    q.push(P(0, 0));

    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        int d = p.first;
        if (dist2[v] < d) {
            continue;
        }
        for (int i = 0; i < g[v].size(); i++) {
            edge &e = g[v][i];
            if (d + e.cost < dist1[e.to]) {
                dist2[e.to] = dist1[e.to];
                dist1[e.to] = d + e.cost;
                q.push(P(d + e.cost, e.to));
            }
            if (d + e.cost < dist2[e.to] && d + e.cost > dist1[e.to]) {
                dist2[e.to] = d + e.cost;
                q.push(P(d + e.cost, e.to));
            }
        }
    }
    cout << dist2[n - 1] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> r;
    for (int i = 0; i < r; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        edge e1, e2;
        e1.to = t;
        e1.cost = c;
        e2.to = s;
        e2.cost = c;
        g[s].push_back(e1);
        g[t].push_back(e2);
    }
    solve();
    return 0;
}
