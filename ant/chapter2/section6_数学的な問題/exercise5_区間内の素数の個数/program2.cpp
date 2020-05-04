#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

bool is_prime[10000];
bool is_prime_small[100000000000];

void segment_sieve(ll a, ll b) {
    int p = 0;
    for (int i = 0; (ll)i * i < b; i++) {
        is_prime_small[i] = true;
    }
    for (int i = 0; i < b - a; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; (ll)i * i < b; i++) {
        if (is_prime_small[i]) {
            for (ll j = 2 * i; j < b; j += i) {
                is_prime_small[j] = false;
            }
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                is_prime[j - a] = false;
            }
        }
    }
}

ll a, b;

int main(int argc, char const *argv[]) {
    cin >> a >> b;
    segment_sieve(a, b);
    int ans = 0;
    for (int i = 0; i < b - a; i++) {
        if (is_prime[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}