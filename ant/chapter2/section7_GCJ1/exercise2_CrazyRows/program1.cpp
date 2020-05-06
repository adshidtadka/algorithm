#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int m[41][41];
int a[41];

void allocate(int row, int pos) {
    for (int i = row; i > pos; i--) {
        swap(a[i], a[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (m[i][j] == 1) {
                a[i] = j;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] <= i) {
                cout << "allocate(" << j << ", " << i << ")" << endl;
                allocate(j, i);
                ans += j - i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}