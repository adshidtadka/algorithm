#include <cmath>
#include <iomanip>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a, b, h, m;
const double PI = M_PI;

int main() {
    cin >> a >> b >> h >> m;
    double rad = (11 * m - 60 * h) * PI / 360;
    double ans = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad));
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
