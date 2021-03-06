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

// geo
//--------------------------------------------
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(x * a, y * a); }
    Point operator/(double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }

    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator==(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
};

typedef Point Vector;

class Segment {
public:
    Point p1, p2;
    Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};

typedef Segment Line;

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

typedef vector<Point> Polygon;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }

double abs(Vector a) { return sqrt(norm(a)); }

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }

enum Position {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ON_SEGMENT = 0,
    ONLINE_FRONT = -2
};

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    enum Position p;
    if (cross(a, b) > EPS)
        p = COUNTER_CLOCKWISE;
    else if (cross(a, b) < -EPS)
        p = CLOCKWISE;
    else if (dot(a, b) < -EPS)
        p = ONLINE_BACK;
    else if (a.norm() < b.norm())
        p = ONLINE_FRONT;
    else
        p = ON_SEGMENT;
    return p;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Point a, Point b) {
    Vector v = a - b;
    return v.abs();
}

double getDistanceLP(Line l, Point p) {
    double c = cross(l.p2 - l.p1, p - l.p1);
    Vector v = l.p2 - l.p1;
    return abs(c) / v.abs();
}

double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

static const int BOTTOM = 0;
static const int LEFT = 1;
static const int RIGHT = 2;
static const int TOP = 3;

class EndPoint {
public:
    Point p;
    int seg, st;
    EndPoint() {}
    EndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {}

    bool operator<(const EndPoint &ep) const {
        if (p.y == ep.p.y)
            return st < ep.st;
        else
            return p.y < ep.p.y;
    }
};

EndPoint EP[2 * 100000];

int manhattanIntersection(vector<Segment> s) {
    int n = s.size();

    for (int i = 0, k = 0; i < n; i++) {
        if (s[i].p1.y == s[i].p2.y) {
            if (s[i].p1.x > s[i].p2.x) swap(s[i].p1, s[i].p2);
        } else if (s[i].p1.y > s[i].p2.y)
            swap(s[i].p1, s[i].p2);
        if (s[i].p1.y == s[i].p2.y) {
            EP[k++] = EndPoint(s[i].p1, i, LEFT);
            EP[k++] = EndPoint(s[i].p2, i, RIGHT);
        } else {
            EP[k++] = EndPoint(s[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(s[i].p2, i, TOP);
        }
    }

    sort(EP, EP + (2 * n));

    set<int> BT;
    BT.insert(INF_INT);
    int cnt = 0;
    REP(i, 2 * n) {
        if (EP[i].st == TOP)
            BT.erase(EP[i].p.x);
        else if (EP[i].st == BOTTOM)
            BT.insert(EP[i].p.x);
        else if (EP[i].st == LEFT) {
            set<int>::iterator b =
                lower_bound(BT.begin(), BT.end(), s[EP[i].seg].p1.x);
            set<int>::iterator e =
                upper_bound(BT.begin(), BT.end(), s[EP[i].seg].p2.x);
            cnt += distance(b, e);
        }
    }
    return cnt;
}

int main(void) {
    int n;
    cin >> n;
    vector<Segment> v;
    REP(i, n) {
        Segment s;
        cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
        v.PB(s);
    }
    cout << manhattanIntersection(v) << endl;
    return 0;
}
