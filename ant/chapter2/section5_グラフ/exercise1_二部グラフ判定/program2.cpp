#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1001];
int v, e;

int color[1001];

bool paint(int vInd, int c) {
    color[vInd] = c;
    for (int i = 0; i < g[vInd].size(); i++) {
        if (color[g[vInd][i]] == c) {
            return false;
        }
        if (color[g[vInd][i]] == 0) {
            if (!paint(g[vInd][i], -c)) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    for (int i = 0; i < v; i++) {
        if (color[i] == 0) {
            if (!paint(i, 1)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(int argc, char const *argv[]) {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    solve();
    return 0;
}
