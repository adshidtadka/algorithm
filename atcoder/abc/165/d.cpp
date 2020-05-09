#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll a, b, n;

int main(int argc, char const *argv[]) {
    cin >> a >> b >> n;
    ll ans = 0;
    if (n <= b - 1) {
        ans = floor(a * n / b);
    } else {
        ans = floor(a * (b - 1) / b);
    }
    cout << ans << endl;
    return 0;
}
