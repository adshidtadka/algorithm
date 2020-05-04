#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    if (n == 1) {
        return false;
    }
    return true;
}

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

map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
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

int x;

int main(int argc, char const *argv[]) {
    cin >> x;
    if (is_prime(x)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
