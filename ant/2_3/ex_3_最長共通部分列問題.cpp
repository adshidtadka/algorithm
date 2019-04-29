#include <iostream>
using namespace std;

const int MAX_N = 1000;
int n, m;
char s[MAX_N], t[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    cin >> n >> m >> s >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << "max value is " << dp[n][m] << endl;

    return 0;
}
