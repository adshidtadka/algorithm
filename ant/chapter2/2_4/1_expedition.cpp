#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10000;

int N, L, P;
int A[MAX_N + 1], B[MAX_N + 1];

void read() {
    cin >> N >> L >> P;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
}

void solve() {
    A[N] = L;
    B[N] = 0;

    priority_queue<int> que;

    int ans = 0, pos = 0, tank = P;
    for (int i = 0; i <= N; i++) {
        int d = A[i] - pos;

        // ガソリンを補給
        while (tank - d < 0) {
            if (que.empty()) {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }

    printf("%d\n", ans);
}

int main(int argc, char const *argv[]) {
    read();
    solve();

    return 0;
}
