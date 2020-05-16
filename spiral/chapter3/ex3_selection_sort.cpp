#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int a[101];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (a[i] != a[minj]) {
            swap(a[i], a[minj]);
            cnt++;
        }
    }
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl << cnt << endl;
    return 0;
}
