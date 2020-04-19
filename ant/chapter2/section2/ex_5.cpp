//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, l[50010];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i];
	}

	LL ans = 0;
	while(n > 1) {
	    int mii1 = 0, mii2 = 1;
	    if (l[mii1] > l[mii2])
	    {
	    	swap(mii1, mii2);
	    }

	    for (int i = 2; i < n; ++i)
	    {
	    	if (l[i] < l[mii1])
	    	{
	    		mii2 = mii1;
	    		mii1 = i;
	    	} else if (l[i] < l[mii2])
	    	{
	    		mii2 = i;
	    	}
	    }

	    int t = l[mii1] + l[mii2];
	    ans += t;

	    if (mii1 == n-1)
	    {
	    	swap(mii1, mii2);
	    }
	    l[mii1] = t;
	    l[mii2] = l[n-1];
	    n--;
	}
	printf("%lld\n", ans);
}


int main() {
	solve();
	return 0;
}






