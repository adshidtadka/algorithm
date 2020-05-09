#include <cmath>
#include <iostream>
#include <vector>

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

int main(int argc, char const* argv[]) {
    cin >> str;
    reverse(str.begin(), str.end());
    int n = (int)str.size();
    vector<int> cnt(mod);
    ll ans = 0;
    mint tot = 0;
    mint x = 1;
    for (int i = 0; i < n; i++) {
        cnt[tot.x]++;
        tot += (str[i] - '0') * x.x;
        ans += cnt[tot.x];
        x *= 10;
    }
    cout << ans << endl;
    return 0;
}
