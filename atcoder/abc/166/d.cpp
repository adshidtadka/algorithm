#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

ll x;

ll calc(ll a, ll b) { return pow(a, 5) - pow(b, 5); }

map<ll, ll> prime_factor(ll n) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
}

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    cin >> x;
    vector<ll> v = divisor(x);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        ll a = v[i] / 2 + 1;
        ll b = a - v[i];
        ll result = calc(a, b);
        while (result <= x) {
            if (result == x) {
                cout << a << " " << b << endl;
                return 0;
            }
            a++;
            b++;
            result = calc(a, b);
        }
    }
    return 0;
}
