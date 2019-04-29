#include <iostream>
using namespace std;

const int MAX_V = 50;
const int MAX_C = 50;

int n;
int v[MAX_V + 1], c[MAX_C + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int rec = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > c[i]) {
            rec += v[i] - c[i];
        }
    }
    cout << rec << endl;

    return 0;
}
