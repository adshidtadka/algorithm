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
    cout << a << " " << b << " " << x << " " << y << endl;
    return d;
}

int main(int argc, char const* argv[]) {
    cin >> a >> b;
    int x, y;
    int d = extgcd(a, b, x, y);
    return 0;
}
