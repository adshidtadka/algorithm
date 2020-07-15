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

class Node {
public:
    int location;
    int p, l, r;
    Node() {}
};

class Point {
public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y) : id(id), x(x), y(y) {}
    bool operator<(const Point &p) const { return id < p.id; }

    void print() { printf("%d\n", id); }
};

static const int MAX = 1000000;
static const int NIL = -1;

int n;
Point P[MAX];
Node T[MAX];
int np;

// sort function
bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

int make2DTree(int l, int r, int depth) {
    if (!(l < r)) return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].l = make2DTree(l, mid, depth + 1);
    T[t].r = make2DTree(mid + 1, r, depth + 1);
    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth,
          vector<Point> &ans) {
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.PB(P[T[v].location]);
    }

    if (depth % 2 == 0) {
        if (T[v].l != NIL) {
            if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    } else {
        if (T[v].l != NIL) {
            if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
}

int main(int argc, char *argv[]) {
    cin >> n;
    REP(i, n) {
        int x, y;
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }
    np = 0;
    int root = make2DTree(0, n, 0);

    int q;
    cin >> q;
    REP(i, q) {
        int sx, tx, sy, ty;
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        vector<Point> ans;
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        REP(j, ans.size()) ans[j].print();
        printf("\n");
    }
    return 0;
}
