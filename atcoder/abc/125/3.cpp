#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 100000;

int n;
int a[MAX_N];

// recが最大公約数かどうか
bool gcd(int rec) {
    int rest_counter = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % rec > 0) {
            // 約数でない
            rest_counter++;
            // 約数でないものが2つある
            if (rest_counter >= 2) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    // a[1]以下が最大公約数の場合
    int rec = a[1];
    while (rec > 0) {
        // recが最大公約数かどうか
        cout << "rec = " << rec << endl;
        if (gcd(rec)) {
            cout << rec << endl;
            return 0;
        } else {
            rec--;
        }
    }
    cout << "error" << endl;
    return 1;
}
