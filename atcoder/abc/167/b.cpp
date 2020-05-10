#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll a, b, c, k;

int main(int argc, char const *argv[]) {
    cin >> a >> b >> c >> k;
    int ans = 0;
    int takeNum = k;
    if (a >= takeNum) {
        ans += k;
        cout << ans << endl;
        return 0;
    } else {
        ans = a;
        takeNum -= a;
    }

    if (b >= takeNum) {
        cout << ans << endl;
        return 0;
    } else {
        takeNum -= b;
    }

    ans -= takeNum;
    cout << ans << endl;
    return 0;
}
