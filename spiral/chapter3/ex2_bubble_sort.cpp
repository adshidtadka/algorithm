#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
int a[101];

int bubbleSort(int x[], int y) {
    int flag = 1;
    int changeNum = 0;
    while (flag) {
        flag = 0;
        for (int j = y - 1; j > 0; j--) {
            if (x[j] < x[j - 1]) {
                swap(x[j], x[j - 1]);
                flag = 1;
                changeNum++;
            };
        }
    }
    return changeNum;
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    int changeNum = bubbleSort(a, n);

    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl << changeNum << endl;
    return 0;
}
