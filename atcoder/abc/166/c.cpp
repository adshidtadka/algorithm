#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
ll h[100001];
int a[100001], b[100001];
int isGood[100001];

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        isGood[i] = true;
    }
    for (int i = 0; i < m; i++) {
        if (h[a[i]] == h[b[i]]) {
            isGood[a[i]] = false;
            isGood[b[i]] = false;
        } else if (h[a[i]] < h[b[i]]) {
            isGood[a[i]] = false;
        } else {
            isGood[b[i]] = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isGood[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
