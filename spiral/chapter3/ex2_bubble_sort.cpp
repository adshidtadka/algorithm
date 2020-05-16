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

    int flag = 1;
    int changeNum = 0;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = 1;
                changeNum++;
            };
        }
    }
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl << changeNum << endl;
    return 0;
}
