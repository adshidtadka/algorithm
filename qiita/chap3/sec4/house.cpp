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

class Matrix {
    int row;     //行
    int column;  //列

    double **p_top;  //配列の最初を指すポインタ

public:
    Matrix(int i = 1, int j = 1);  //コンストラクタ
    Matrix(const Matrix &cp);      //コピーコンストラクタ

    ~Matrix();  //デストラクタ

    int row_size() { return (row); }
    int column_size() { return (column); }

    void change_size(int i, int j);  //行列のサイズを変更する

    //演算子のオーバーロード
    double *&operator[](int i) { return (p_top[i]); }
    Matrix operator=(const Matrix &a);
    Matrix operator+(const Matrix &a);
    Matrix operator-(const Matrix &a);
    Matrix operator*(const Matrix &a);

    friend Matrix operator*(const Matrix &a, double b);
    friend Matrix operator*(double b, const Matrix &a);
    friend Matrix operator%(const Matrix &a, int b);

    //行列の変換など
    void unit_matrix();   //単位行列にする
    Matrix transposed();  //転置行列をかえす
};

//---------------------------------
//     通常のコンストラクタ
//---------------------------------
Matrix::Matrix(int i, int j) {
    //  i,j のチェック
    if (i < 1 || j < 1) {
        cerr << "err Matrix::Matrix" << endl;
        exit(1);
    }

    row = i;
    column = j;

    //  配列のメモリ領域を動的に確保
    p_top = new double *[row + 1];
    *p_top = new double[row * column + 1];
    // +1 ga daiji kore tukenaito bagu ga deta
    for (int k = 1; k <= row; k++) *(p_top + k) = *p_top + ((k - 1) * column);

    //  値の初期化
    for (int k1 = 1; k1 <= row; k1++) {
        for (int k2 = 1; k2 <= column; k2++) {
            p_top[k1][k2] = 0;
        }
    }
}

//---------------------------------
//     コピーコンストラクタ
//---------------------------------
Matrix::Matrix(const Matrix &cp) {
    row = cp.row;
    column = cp.column;

    //  配列のメモリ領域を動的に確保
    p_top = new double *[row + 1];
    *p_top = new double[row * column + 1];
    // +1 ga daiji kore tukenaito bagu ga deta
    for (int k = 1; k <= row; k++) *(p_top + k) = *p_top + ((k - 1) * column);

    //  値のコピー
    for (int k1 = 1; k1 <= row; k1++) {
        for (int k2 = 1; k2 <= column; k2++) {
            p_top[k1][k2] = cp.p_top[k1][k2];
        }
    }
}

//----------------------
//   デストラクタ
//----------------------
Matrix::~Matrix() {
    delete[] * p_top;
    delete[] p_top;
}

//------------------------------
//   行列の大きさを変える  値は０
//------------------------------
void Matrix::change_size(int i, int j) {
    //  i,j のチェック
    if (i < 1 || j < 1) {
        cerr << "err Matrix::change_size" << endl;
        exit(1);
    }

    delete[] * p_top;
    delete[] p_top;

    row = i;
    column = j;

    //  配列のメモリ領域を動的に確保
    p_top = new double *[row + 1];
    *p_top = new double[row * column + 1];
    // +1 ga daiji kore tukenaito bagu ga deta
    for (int k = 1; k <= row; k++) *(p_top + k) = *p_top + ((k - 1) * column);

    //  値の初期化
    for (int k1 = 1; k1 <= row; k1++) {
        for (int k2 = 1; k2 <= column; k2++) {
            p_top[k1][k2] = 0;
        }
    }
}

//------------------------------------
//     代入
//------------------------------------
Matrix Matrix::operator=(const Matrix &a) {
    if (row != a.row || column != a.column) {
        change_size(a.row, a.column);
    }

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            p_top[i][j] = a.p_top[i][j];
        }
    }
    return (*this);
}

//------------------------------------
//       行列の加算
//------------------------------------
Matrix Matrix::operator+(const Matrix &a) {
    if (row != a.row || column != a.column) {
        cerr << "err Matrix::operator+" << endl;
        cerr << "  not equal matrix size" << endl;
        exit(0);
    }

    Matrix r(row, column);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            r.p_top[i][j] = p_top[i][j] + a.p_top[i][j];
        }
    }
    return (r);
}

//------------------------------------
//       行列の減算
//------------------------------------
Matrix Matrix::operator-(const Matrix &a) {
    if (row != a.row || column != a.column) {
        cerr << "err Matrix::operator-" << endl;
        cerr << "  not equal matrix size" << endl;
        exit(0);
    }

    Matrix r(row, column);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            r.p_top[i][j] = p_top[i][j] - a.p_top[i][j];
        }
    }
    return (r);
}

//------------------------------------
//       行列の積
//------------------------------------
Matrix Matrix::operator*(const Matrix &a) {
    if (column != a.row) {
        cerr << "err Matrix::operator*" << endl;
        cerr << "  not equal matrix size" << endl;
        exit(0);
    }

    Matrix r(row, a.column);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= a.column; j++) {
            for (int k = 1; k <= column; k++) {
                r.p_top[i][j] += p_top[i][k] * a.p_top[k][j];
            }
        }
    }
    return (r);
}

//--------------------------------------
//       行列の定数倍
//--------------------------------------
Matrix operator*(const Matrix &a, double b) {
    Matrix r(a.row, a.column);
    for (int i = 1; i <= a.row; i++) {
        for (int j = 1; j <= a.column; j++) {
            r[i][j] = b * a.p_top[i][j];
        }
    }
    return (r);
}
Matrix operator*(double b, const Matrix &a) {
    Matrix r(a.row, a.column);
    for (int i = 1; i <= a.row; i++) {
        for (int j = 1; j <= a.column; j++) {
            r[i][j] = b * a.p_top[i][j];
        }
    }
    return (r);
}

//--------------------------------------
//       行列の剰余
//--------------------------------------
Matrix operator%(const Matrix &a, int b) {
    Matrix r(a.row, a.column);
    for (int i = 1; i <= a.row; i++) {
        for (int j = 1; j <= a.column; j++) {
            r[i][j] = (int)a.p_top[i][j] % b;
        }
    }
    return (r);
}

//----------------------------------------
//  単位行列にする
//----------------------------------------
void Matrix::unit_matrix() {
    if (row != column) {
        cerr << "err in Matrix::unit_matrix()" << endl;
        exit(0);
    }

    int n = row;
    double **a = p_top;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
            if (i == j) a[i][j] = 1;
        }
    }
}

//----------------------------------------
//  転置行列をかえす
//----------------------------------------
Matrix Matrix::transposed() {
    Matrix t(column, row);
    double **a = p_top;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            t[j][i] = a[i][j];
        }
    }
    return (t);
}

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt<MOD>;

// 行列演算
VVEC<mint> mIdentity(LL n) {
    VVEC<mint> A(n, VEC<mint>(n));
    for (int i = 0; i < n; ++i) A[i][i] = 1;
    return A;
}

VVEC<mint> mMul(const VVEC<mint> &A, const VVEC<mint> &B) {
    VVEC<mint> C(A.size(), VEC<mint>(B[0].size()));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k) C[i][j] += A[i][k] * B[k][j];
    return C;
}
// O( n^3 log e )
VVEC<mint> mPow(const VVEC<mint> &A, LL e) {
    return e == 0
               ? mIdentity(A.size())
               : e % 2 == 0 ? mPow(mMul(A, A), e / 2) : mMul(A, mPow(A, e - 1));
}

int h, r;
int g[16][16];
mint dp[1 << 16][16][16];

int main(void) {
    cin >> h >> r;
    REP(i, r) REP(j, r) cin >> g[i][j];
    REP(i, r) dp[1 << i][i][i] = 1;
    VVEC<mint> a(r, VEC<mint>(r, 0));
    REP(s, s << r) REP(st, r) REP(nw, r) {
        REP(nx, r) {
            if (s << nx & 1 || g[nw][nx] == 0) continue;
            dp[s | 1 << nx][st][nx] += dp[s][st][nw];
        }
        a[nw][st] += dp[s][st][nw];
    }
    VVEC<mint> x(r, VEC<mint>(1, 0));
    x[0][0] = 1;
    cout << mMul(mPow(a, h), x)[0][0] << endl;
    return 0;
}
