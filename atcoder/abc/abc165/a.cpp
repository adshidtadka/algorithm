#include <iostream>

using namespace std;

int k, a, b;

int main(int argc, char const *argv[]) {
    cin >> k >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
    return 0;
}
