// include
//------------------------------------------
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// conversion
//------------------------------------------
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

// math
//-------------------------------------------
template <class T>
inline T sqr(T x) {
    return x * x;
}

// typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// container util
//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i, c) \
    for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

// repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
//--------------------------------------------
// const double EPS = 1e-10;
// const double PI = acos(-1.0);

// clear memory
#define CLR(a) memset((a), 0, sizeof(a))

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                           \
    cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
         << " " << __FILE__ << endl;

const int MAX_N = 50000;
const int MAX_K = 100000;

// union find
// --------------------------------------------
int par[MAX_N];
int depth[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        depth[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (depth[x] < depth[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (depth[x] == depth[y]) depth[x]++;
    }
}

bool same(int x, int y) { return find(x) == find(y); }

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> T[i] >> X[i] >> Y[i];
    }

    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;  // 0...N-1

        // 正しくない番号
        if (x < 0 || x >= N || y < 0 || y >= N) {
            ans++;
            continue;
        }

        if (t == 1) {
            // xとyは同じ種類という情報
            if (same(x, y + N) || same(x, y + N * 2)) {
                ans++;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        } else {
            if (same(x, y) || same(x, y + N * 2)) {
                ans++;
            } else {
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + N * 2, y);
            }
        }
    }
    printf("number of wrong info is %d\n", ans);
}

int main() {
    solve();
    return 0;
}
