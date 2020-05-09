#include <iostream>

using namespace std;

int n, k;
int d[101], a[101][101];
bool isHave[101];

int main(int argc, char const *argv[]) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        isHave[i] = false;
    }

    for (int i = 0; i < k; i++) {
        cin >> d[i];
        for (int j = 0; j < d[i]; j++) {
            cin >> a[i][j];
            if (!isHave[a[i][j]]) {
                isHave[a[i][j]] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!isHave[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
