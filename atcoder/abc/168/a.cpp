#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;

int main() {
    cin >> n;
    int x = n % 10;
    if (x == 3) {
        cout << "bon" << endl;
    } else if (x == 0 || x == 1 || x == 6 || x == 8) {
        cout << "pon" << endl;
    } else {
        cout << "hon" << endl;
    }
    return 0;
}
