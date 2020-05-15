#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

vector<vector<mint> > vec;

int n;
int c[200001];

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

int firstNum(int length) {
    int res = 0;
    for(int i = 0;i < length; i++) {
        res += nCr(length - 1, i) * (i + 1);
    }
    return res;
}

void dfs(int index) {
    vector<mint> v;
    v.push_back(firstNum(index));
    for(int i = 1; i < index; i++) {
        v.push_back(vec[index -2][i - 1] * 2);
    }
    vec.push_back(v);
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c + n);
    vector<mint> v = {1};
    vec.push_back(v);
    for(int i = 2; i <= n; i++) {
        dfs(i);
    }
    mint ans = 0;
    for(int i = 0; i < n; i++) {
        ans += vec[n - 1][i] * c[i];
    }
    ans = ans * pow(2, n);
    cout << ans << endl;
    return 0;
}
