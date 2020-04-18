#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// 部分和問題

int n;
int a[22];
int k;

bool dfs(int index, int sum) {
    if (index == n) {
        return sum == k;
    }
    if (dfs(index + 1, sum + a[index])) {
        return true;
    }
    if (dfs(index + 1, sum)) {
        return true;
    }
    return false;
}

void solve() {
    if (dfs(0, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;

    solve();

    return 0;
}
