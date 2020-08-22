// include
//------------------------------------------
#include <bits/stdc++.h>

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
typedef long long LL;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<LL> VL;
typedef vector<VL> VVL;
template <class T>
using VEC = vector<T>;
template <class T>
using VVEC = vector<VEC<T>>;

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
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

// constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF_INT = 2147483647;
const LL INF_LL = 9223372036854775807;
const int MOD = 1000000007;

// clear memory
//--------------------------------------------
#define CLR(a) memset((a), 0, sizeof(a))

// vector
//--------------------------------------------
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}

// pair
//--------------------------------------------
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// vector
//--------------------------------------------
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

// list
//--------------------------------------------
template <typename T>
ostream &operator<<(ostream &os, const list<T> &lst) {
    os << "{";
    REPI(itr, lst) {
        os << *itr;
        itr++;
        if (itr != lst.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// map
//--------------------------------------------
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// set
//--------------------------------------------
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    REPI(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// dump
//--------------------------------------------
#define DUMPOUT cerr

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                       \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                     \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" \
            << endl                                                     \
            << "    ",                                                  \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

int W, H, N;
int X1[500], X2[500], Y1[500], Y2[500];

bool fld[500 * 6][500 * 6];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int compress(int *x1, int *x2, int w) {
    VI xs;
    REP(i, N) FOR(d, -1, 2) {
        int tx1 = x1[i] + d, tx2 = x2[i] + d;
        if (1 <= tx1 && tx1 <= w) xs.PB(tx1);
        if (1 <= tx2 && tx2 <= w) xs.PB(tx2);
    }
    SORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    REP(i, N) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return SZ(xs);
}

int main(void) {
    cin >> W >> H >> N;
    REP(i, N) cin >> X1[i];
    REP(i, N) cin >> X2[i];
    REP(i, N) cin >> Y1[i];
    REP(i, N) cin >> Y2[i];

    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    memset(fld, 0, sizeof(fld));
    REP(i, N)
    FOR(y, Y1[i], Y2[i] + 1) FOR(x, X1[i], X2[i] + 1) fld[y][x] = true;

    int ans = 0;
    REP(y, H) REP(x, W) {
        if (fld[y][x]) continue;
        ans++;

        queue<pair<int, int>> que;
        que.push(MP(x, y));
        while (!que.empty()) {
            int sx = que.front().first, sy = que.front().second;
            que.pop();
            REP(i, 4) {
                int tx = sx + dx[i], ty = sy + dy[i];
                if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
                if (fld[ty][tx]) continue;
                que.push(MP(tx, ty));
                fld[ty][tx] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
