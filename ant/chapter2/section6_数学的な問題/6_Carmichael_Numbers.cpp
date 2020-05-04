#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int n;

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

int main(int argc, char const *argv[]) {
    cin >> n;
    if (is_prime(n)) {
        cout << "No" << endl;
        return 1;
    }
    for (ll i = 2; i < n; i++) {
        if (mod_pow(i, n, n) != i) {
            cout << "No" << endl;
            return 1;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
