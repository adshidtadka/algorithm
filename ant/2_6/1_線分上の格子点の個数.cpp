#include <iostream>
#include <vector>

using namespace std;

int x_1, x_2, y_1, y_2;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char const *argv[]) {
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    int x_diff = abs(x_1 - x_2);
    int y_diff = abs(y_1 - y_2);

    cout << gcd(x_diff, y_diff) - 1 << endl;

    return 0;
}
