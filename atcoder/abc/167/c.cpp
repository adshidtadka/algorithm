#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m, x;
int c[13];
int a[13][13];
int INF = 9999999;

struct Takahashi {
    int cost;
    int rikai[12];
};

int dfs(Takahashi t, int book) {
    bool rikaiAll = true;
    for (int i = 0; i < m; i++) {
        if (t.rikai[i] < x) {
            rikaiAll = false;
            break;
        }
    }
    if (rikaiAll) {
        return t.cost;
    } else if (book >= n) {
        return INF;
    }
    // 買わない場合
    Takahashi tNo = t;
    int no = dfs(tNo, book + 1);
    // 買う場合
    Takahashi tYes = t;
    tYes.cost += c[book];
    for (int i = 0; i < m; i++) {
        tYes.rikai[i] += a[book][i];
    }
    int yes = dfs(tYes, book + 1);
    return min(no, yes);
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int rikai[m];
    memset(rikai, 0, m);
    Takahashi t = {0, {*rikai}};
    int ans = dfs(t, 0);
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
