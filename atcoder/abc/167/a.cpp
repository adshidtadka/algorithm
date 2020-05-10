#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string s;
string t;

int main() {
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}