#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int INF = 99999999;

struct edge {
    int to, cost;
};
typedef pair<int, int> P;  // firstは最短距離, secondは頂点の番号

int N, R, E;
vector<edge> G[MAX_N];  // グラフの隣接リスト表現
int dist[MAX_N];
int dist2[MAX_N];

void read() {
    cin >> N >> R >> E;

    for (int i = 0; i < E; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        edge x, y;
        x.to = s;
        y.to = t;
        x.cost = c;
        y.cost = c;
        G[s].push_back(y);
        G[t].push_back(x);
    }
}

void solve() {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + N, INF);
    fill(dist2, dist2 + N, INF);

    // 発ノード
    dist[0] = 0;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        int d = p.first;

        if (dist2[v] < d) {
            // 2番目の最短路より長い
            continue;
        }

        // vと隣接している頂点を更新
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2) {
                // 最短より短い場合
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2) {
                // ２番目より短い場合
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N - 1]);
}

int main(int argc, char const *argv[]) {
    read();
    solve();
    return 0;
}
