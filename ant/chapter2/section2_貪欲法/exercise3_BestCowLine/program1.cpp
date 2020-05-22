#include <cmath>
#include <iostream>
using namespace std;

int N;
char s[100000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    int a = 0, b = N - 1;

    while (a <= b) {
        //左からと右からを比較
        bool left = false;
        for (int i = 0; a + i <= b; ++i) {
            if (s[a + i] < s[b - i]) {
                left = true;
                break;
            } else if (s[a + i] > s[b - i]) {
                left = false;
                break;
            }
        }
        if (left) {
            putchar(s[a++]);
        } else {
            putchar(s[b--]);
        }
    }
    putchar('\n');
}

int main() {
    solve();

    return 0;
}
