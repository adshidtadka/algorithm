#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int a[101];

int selectionSort(int x[], int y) {
    int cnt = 0;
    for (int i = 0; i < y; i++) {
        int minj = i;
        for (int j = i; j < y; j++) {
            if (x[j] < x[minj]) {
                minj = j;
            }
        }
        if (x[i] != x[minj]) {
            swap(x[i], x[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    int cnt = selectionSort(a, n);
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl << cnt << endl;
    return 0;
}
