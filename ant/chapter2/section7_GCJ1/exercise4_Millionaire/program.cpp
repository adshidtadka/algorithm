#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int m;
double p;
int x;

struct Status {
    int money;
    double prob;
};

int savedMoney[16];

int main() {
    cin >> m >> p >> x;
    queue<Status> q;

    // need money
    savedMoney[m] = 1000000;
    savedMoney[m + 1] = 99999999;
    for (int i = m - 1; i >= 1; i--) {
        savedMoney[i] = ceil(savedMoney[i + 1] / 2);
    }

    double ans = 0;
    q.push({600000, 1});
    for (int i = 1; i <= m + 1; i++) {
        queue<Status> newQ;
        cout << "---- round:" << i << " ----" << endl;
        cout << "savedMoney:" << savedMoney[i] << endl;
        while (!q.empty()) {
            Status now = q.front();
            q.pop();
            if (now.money >= 1000000) {
                ans += now.prob;
                cout << "over now:" << now.money << ", " << now.prob << endl
                     << endl;
            } else if (now.money * 2 >= savedMoney[i]) {
                int bet;
                if (now.money >= savedMoney[i]) {
                    bet = min(now.money - savedMoney[i], 1000000 - now.money);
                } else {
                    bet = ceil(savedMoney[i] / 2);
                }
                cout << "now:" << now.money << ", " << now.prob << endl;
                cout << "bet:" << bet << endl;
                Status win;
                win.money = now.money + bet;
                win.prob = now.prob * p;
                cout << "win:" << win.money << ", " << win.prob << endl;
                newQ.push(win);
                Status lose;
                lose.money = now.money - bet;
                lose.prob = now.prob * (1 - p);
                newQ.push(lose);
                cout << "lose:" << lose.money << ", " << lose.prob << endl;
                cout << endl;
            }
        }
        q = newQ;
    }
    cout << ans << endl;
    return 0;
}