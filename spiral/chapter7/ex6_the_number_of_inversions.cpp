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

const int MAX = 200000;
int l[MAX / 2 + 2], r[MAX / 2 + 2];

LL merge(int a[], int n, int left, int mid, int right) {
    LL cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    REP(i, n1) l[i] = a[left + i];
    REP(i, n2) r[i] = a[mid + i];
    l[n1] = r[n2] = INF_INT;
    int i = 0, j = 0;
    FOR(k, left, right) {
        if (l[i] <= r[j]) {
            a[k] = l[i++];
        } else {
            a[k] = r[j++];
            cnt += n1 - i;
        }
    }
    return cnt;
}

LL mergeSort(int a[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        LL v1 = mergeSort(a, n, left, mid);
        LL v2 = mergeSort(a, n, mid, right);
        LL v3 = merge(a, n, left, mid, right);
        return v1 + v2 + v3;
    } else
        return 0;
}

int main(void) {
    int n;
    int a[MAX];
    cin >> n;
    REP(i, n) cin >> a[i];
    LL ans = mergeSort(a, n, 0, n);
    cout << ans << endl;
    return 0;
}