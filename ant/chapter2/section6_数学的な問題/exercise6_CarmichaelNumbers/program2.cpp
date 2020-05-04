#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

// 素数判定
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int n, m;

int main(int argc, char const *argv[]) {
    cin >> m;
    for (int n = 1; n <= m; n++) {
        if (is_prime(n)) {
            cout << "No: " << n << endl;
            continue;
        }
        bool isBreak = false;
        for (ll i = 2; i < n; i++) {
            if (mod_pow(i, n, n) != i) {
                cout << "No: " << n << endl;
                isBreak = true;
                break;
            }
        }
        if (!isBreak) {
            cout << "Yes: " << n << endl;
        }
    }
    return 0;
}
