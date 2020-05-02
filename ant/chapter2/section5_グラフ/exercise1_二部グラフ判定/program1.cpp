#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 10000;

vector<int> G[MAX_V];
int V, E;

int color[MAX_V];

//頂点を1と-1で塗っていく
bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        // 隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c) {
            return false;
        }
        // 隣接している頂点がまだ塗られていないなら-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    for (int i = 0; i < V; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                printf("No\n");
                return 1;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
