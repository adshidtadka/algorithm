#include <iostream>

using namespace std;

int a, b, c, d;

int main(int argc, char const *argv[]) {
    cin >> a >> b >> c >> d;
    int takahashiAttack = (c + (b - 1)) / b;
    int aokiAttack = (a + (d - 1)) / d;
    if (takahashiAttack <= aokiAttack) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
