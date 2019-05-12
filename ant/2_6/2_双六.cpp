#include <iostream>
#include <vector>

using namespace std;

int a, b;

int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main(int argc, char const* argv[]) {
    cin >> a >> b;

    int x, y, x_, y_;

    extgcd(a, b, x, y);

    if (x >= 0) {
        cout << x << " ";
        x_ = 0;
    } else {
        cout << 0 << " ";
        x_ = -x;
    }
    if (y >= 0) {
        cout << y << " ";
        y_ = 0;
    } else {
        cout << 0 << " ";
        y_ = -y;
    }

    cout << x_ << " " << y_ << endl;

    return 0;
}
