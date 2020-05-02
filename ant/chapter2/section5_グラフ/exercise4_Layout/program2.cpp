#include <iostream>

using namespace std;

struct edge {
    int from, to, cost;
};

const int MAX_V = 20001;
const int MAX_E = 20001;
const int INF = 99999999;

edge es[MAX_E];
int d[MAX_V];
int V, E;

int belmanford(int s) {
    for (int i = 0; i <= V; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) {
            break;
        }
    }
    return d[V];
}

int N, ML, MD;
int AL[10001], BL[10001], DL[10001];
int AD[10001], BD[10001], DD[10001];

void solve() {
    V = N;
    E = V - 1 + ML + MD;
    for (int i = 0; i < N - 1; i++) {
        es[i] = (edge){i + 1, i, 0};
    }
    for (int i = 0; i < ML; i++) {
        int index = i + N - 1;
        es[index] = (edge){AL[i], BL[i], DL[i]};
    }
    for (int i = 0; i < MD; i++) {
        int index = i + N - 1 + ML;
        es[index] = (edge){BD[i], AD[i], -DD[i]};
    }
    for (int i = 0; i < E; i++) {
        edge e = es[i];
    }

    cout << belmanford(1) << endl;
}

int main(int argc, char const *argv[]) {
    cin >> N >> ML >> MD;
    for (int i = 0; i < ML; i++) {
        cin >> AL[i] >> BL[i] >> DL[i];
    }
    for (int i = 0; i < MD; i++) {
        cin >> AD[i] >> BD[i] >> DD[i];
    }
    solve();
    return 0;
}
