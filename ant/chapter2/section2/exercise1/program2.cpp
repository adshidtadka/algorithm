#include <iostream>

using namespace std;

const int v[6] = {1, 5, 10, 50, 100, 500};
int c[7];
int a;

void solve() {
    int total = 0;
    int ans = 0;
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < c[i]; j++) {
            if (total + v[i] == a) {
                cout << ans + 1 << endl;
            } else if (total + v[i] < a) {
                total += v[i];
                ans++;
            } else if (total + v[i] < a) {
                break;
            }
        }
    }
}

void solveAns() {
    int ans = 0;
    for (int i = 5; i >= 0; i--) {
        int t = min(a / v[i], c[i]);
        a -= t * v[i];
        ans += t;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 6; i++) {
        cin >> c[i];
    }
    cin >> a;
    solveAns();
    return 0;
}
