#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 100000000;
const int MAX_SORT_B = 100000000;

typedef long long ll;

bool is_prime[MAX_N];
bool is_prime_small[MAX_SORT_B];
int a, b;

void segment_sieve(ll a, ll b) {
    for (int i = 0; (ll)i * i < b; i++) {
        is_prime_small[i] = true;
    }
    for (int i = 0; i < b - a; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; (ll)i * i < b; i++) {
        if (is_prime_small[i]) {
            for (int j = 2 * i; (ll)j * j < b; j += i) {
                is_prime_small[j] = false;
            }
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                is_prime[j - a] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> a >> b;
    segment_sieve(a, b);
    int counter = 0;
    for (int i = a; i <= b; i++) {
        if (is_prime[i - a]) {
            counter++;
            printf("%d\n", i);
        }
    }
    cout << counter << endl;
    return 0;
}
