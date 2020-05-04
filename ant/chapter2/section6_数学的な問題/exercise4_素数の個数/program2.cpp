#include <iostream>
#include <map>
#include <vector>

using namespace std;

int prime[10000];     // i番目の素数
int is_prime[10000];  // iが素数ならtrue

int sieve(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

int x;

int main(int argc, char const *argv[]) {
    cin >> x;
    cout << sieve(x) << endl;
    return 0;
}
