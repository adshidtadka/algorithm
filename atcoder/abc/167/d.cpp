#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll n, k;
ll a[2000000];

vector<ll> v;
set<ll> s;

int main(int argc, char const *argv[]) {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll pos = 1;
    v.push_back(pos);
    s.insert(pos);
    for (ll i = 0; i < k; i++) {
        ll nextPos = a[pos];
        if (s.find(nextPos) != s.end()) {
            auto result = find(v.begin(), v.end(), nextPos);
            ll relPos = distance(v.begin(), result);
            ll repeatNum = distance(result, v.end());
            pos = v[(k - relPos) % repeatNum + relPos];
            cout << pos << endl;
            return 0;
        }
        v.push_back(nextPos);
        s.insert(nextPos);
        pos = nextPos;
    }
    cout << pos << endl;
    return 0;
}