#include <iostream>
using namespace std;

int n;
char s[100000];

void solve() {
    int a = 0;
    int b = n - 1;
    while (a <= b) {
        for (int i = 0; i <= (b - a + 1) / 2; i++) {
            if (s[a + i] < s[b - i]) {
                cout << s[a];
                a++;
                break;
            } else if (s[a + i] > s[b - i]) {
                cout << s[b];
                b--;
                break;
            } else if (i == (b - a) / 2) {
                cout << s[a];
                a++;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    cin >> n;
    cin >> s;
    solve();
    return 0;
}
