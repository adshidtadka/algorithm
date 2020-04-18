#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 素数判定
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 約数の列挙
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

// 素因数分解
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
}

int n;

int main(int argc, char const *argv[]) {
    cin >> n;
    if (is_prime(n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    vector<int> div = divisor(n);
    for (int i = 0; i < div.size(); i++) {
        cout << div[i] << " ";
    }
    cout << endl;
    map<int, int> fac = prime_factor(n);
    for (int i = 0; i < fac.size(); i++) {
        cout << fac[i] << " ";
    }
    cout << endl;
    return 0;
}
