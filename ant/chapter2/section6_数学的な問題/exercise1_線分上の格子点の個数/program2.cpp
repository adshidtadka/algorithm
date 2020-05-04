#include <iostream>

using namespace std;

int x1, y1, x2, y2;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << gcd(abs(x2 - x1), abs(y2 - y1)) - 1 << endl;
    return 0;
}
