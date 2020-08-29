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

const int ST_SIZE = (1 << 15) - 1;

int N, C;
int L[10000];
int S[10000], A[10000];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

double prv[10000];

void init(int k, int l, int r) {
    ang[k] = vx[k] = 0.0;
    if (r - l == 1)
        vy[k] = L[l];
    else {
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, l, (l + r) / 2);
        init(chr, (l + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];
    }
}

void change(int k, double a, int v, int l, int r) {
    if (k <= l)
        return;
    else if (k < r) {
        int chl = v * 2 + 1, chr = v * 2 + 2;
        int m = (l + r) / 2;
        change(k, a, chl, l, m);
        change(k, a, chr, m, r);
        if (k <= m) ang[v] += a;
        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
    }
}

int main(void) {
    cin >> N >> C;
    REP(i, N) cin >> L[i];
    REP(i, C) cin >> S[i];
    REP(i, C) cin >> A[i];

    init(0, 0, N);
    FOR(i, 1, N) prv[i] = M_PI;

    REP(i, C) {
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI;
        change(s, a - prv[s], 0, 0, N);
        prv[s] = a;
        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
    return 0;
}
