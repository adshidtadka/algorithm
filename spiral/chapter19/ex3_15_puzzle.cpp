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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

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

#define N 4
#define N2 16

static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'l', 'd', 'r'};
int mdt[N2][N2];

struct Puzzle {
    int f[N2], space, md;
    int cost;

    bool operator<(const Puzzle &p) const {
        REP(i, N2) {
            if (f[i] == p.f[i]) continue;
            return f[i] < p.f[i];
        }
        return false;
    }
};

struct State {
    Puzzle p;
    int e;
    bool operator<(const State &s) const { return e > s.e; }
};

int getAllMd(Puzzle p) {
    int sum = 0;
    REP(i, N2) {
        if (p.f[i] == N2) continue;
        sum += mdt[i][p.f[i] - 1];
    }
    return sum;
}

int astar(Puzzle p) {
    priority_queue<State> pq;
    p.md = getAllMd(p);
    p.cost = 0;
    map<Puzzle, bool> m;
    State init;
    init.p = p;
    init.e = p.md;
    pq.push(init);

    while (!pq.empty()) {
        State st = pq.top();
        pq.pop();
        Puzzle u = st.p;
        if (u.md == 0) return u.cost;
        m[u] = true;

        int sx = u.space / N;
        int sy = u.space % N;
        REP(i, 4) {
            int tx = sx + dx[i];
            int ty = sy + dy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
            Puzzle v = u;
            v.md -= mdt[tx * N + ty][v.f[tx * N + ty] - 1];
            v.md += mdt[sx * N + sy][v.f[tx * N + ty] - 1];

            swap(v.f[sx * N + sy], v.f[tx * N + ty]);
            v.space = tx * N + ty;
            if (!m[v]) {
                v.cost++;
                State news;
                news.p = v;
                news.e = v.cost + v.md;
                pq.push(news);
            }
        }
    }
    return -1;
}

int main(void) {
    REP(i, N2) REP(j, N2) mdt[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
    Puzzle in;
    REP(i, N2) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }
    cout << astar(in) << endl;
    return 0;
}
