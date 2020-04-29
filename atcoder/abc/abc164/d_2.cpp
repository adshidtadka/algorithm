#include <cmath>
#include <iostream>

typedef long long ll;

using namespace std;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 2019;
struct mint {
    ll x;  // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

string str;
int a[200001];
mint s[200001];

int main(int argc, char const* argv[]) {
    cin >> str;
    int n = (int)str.size();
    int ans = 0;
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + ((ll)str[n - i - 1] - '0') * (ll)pow(10, i);
        for (int j = 0; j < i - 3; j++) {
            if (s[i + 1].x == s[j].x) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
