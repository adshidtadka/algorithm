#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_ML = 10000;
const int MAX_MD = 10000;
const int MAX_N = 1000;
const int INF = 99999999;

int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N];
bool updated;

void read() {
    cin >> N >> ML >> MD;
    for (int i = 0; i < ML; i++) {
        cin >> AL[i] >> BL[i] >> DL[i];
    }
    for (int i = 0; i < MD; i++) {
        cin >> AD[i] >> BD[i] >> DD[i];
    }
}

void update(int& x, int y) {
    if (x > y) {
        x = y;
        updated = true;
    }
}

void bellmanford() {
    for (int k = 0; k <= N; k++) {
        updated = false;
        // i+1からiへコスト0
        for (int i = 0; i + 1 < N; i++) {
            if (d[i + 1] < INF) {
                update(d[i], d[i + 1]);
            }
        }
        // ALからBLへコストDL
        for (int i = 0; i < ML; i++) {
            if (d[AL[i] - 1] < INF) {
                update(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
            }
        }
        // BDからADへコスト-DD
        for (int i = 0; i < MD; i++) {
            if (d[BD[i] - 1] < INF) {
                update(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
            }
        }
    }
}

void solve() {
    // 負閉路チェック
    fill(d, d + N, 0);
    bellmanford();
    if (updated) {
        printf("%d\n", -1);
        return;
    }

    fill(d, d + N, INF);
    d[0] = 0;
    bellmanford();
    int res = d[N - 1];
    if (res == INF) {
        res = -2;
    }
    printf("%d\n", res);
}

int main(int argc, char const* argv[]) {
    read();
    solve();
    return 0;
}
