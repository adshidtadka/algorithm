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

struct Node {
    int p, l, r;
};

Node T[100001];
int n, D[100001], H[100001];

void setDepth(int u, int d) {
    if (u == -1) return;
    D[u] = d;
    setDepth(T[u].l, d + 1);
    setDepth(T[u].r, d + 1);
}

int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].l != -1) h1 = setHeight(T[u].l) + 1;
    if (T[u].r != -1) h2 = setHeight(T[u].r) + 1;
    return H[u] = max(h1, h2);
}

int getSibling(int u) {
    if (T[u].p == -1) return -1;
    if (T[T[u].p].l != u && T[T[u].p].l != -1) return T[T[u].p].l;
    if (T[T[u].p].r != u && T[T[u].p].r != -1) return T[T[u].p].r;
    return -1;
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    int deg = 0;
    if (T[u].l != -1) deg++;
    if (T[u].r != -1) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if (T[u].p == -1)
        cout << "root";
    else if (T[u].l == -1 && T[u].r == -1)
        cout << "leaf";
    else
        cout << "internal node";
    cout << endl;
}

int main(int argc, char *argv[]) {
    cin >> n;
    REP(i, n) T[i].p = -1;
    REP(i, n) {
        int v, l, r;
        cin >> v >> l >> r;
        T[v].l = l;
        T[v].r = r;
        if (l != -1) T[l].p = v;
        if (r != -1) T[r].p = v;
    }
    int r;
    REP(i, n) if (T[i].p == -1) r = i;
    setDepth(r, 0);
    setHeight(r);
    REP(i, n) print(i);
    return 0;
}
