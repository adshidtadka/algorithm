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

    for (int k = 0; k < n; k++) {
        if (k > 0) cout << " ";
        cout << a[k];
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int k = 0; k < n; k++) {
            if (k > 0) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }
    return 0;
}
