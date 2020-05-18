#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll cnt;
int n;
int a[1000001];
int l;
vector<int> g;

void insertionSort(int a[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = v;
    }
}

void shellSort(int a[], int n) {
    for (int h = 1;;) {
        if (h > n) break;
        g.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = g.size() - 1; i >= 0; i--) {
        insertionSort(a, n, g[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cnt = 0;
    shellSort(a, n);

    cout << g.size() << endl;
    for (int i = g.size() - 1; i >= 0; i--) {
        cout << g[i];
        if (i) cout << " ";
    }
    cout << endl << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
