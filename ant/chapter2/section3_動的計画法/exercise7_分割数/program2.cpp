#include <algorithm>
#include <iostream>
<<<<<<< HEAD

using namespace std;

int n, m;
int M;
int dp[1001][1001];

void solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = dp[i][j - i] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << dp[m][n] << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> M;
    solve();
=======
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
int M;

int dp[MAX_M + 1][MAX_N + 1];

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    cin >> M;

    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[m][n] % M);
>>>>>>> 0a6f05bc6c0bb2798c95ed096cf790dd98a93207
    return 0;
}
