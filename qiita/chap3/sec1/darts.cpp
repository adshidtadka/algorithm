// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#ifdef GXX_EXPERIMENTAL_CXX0X
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#ifdef GXX_EXPERIMENTAL_CXX0X
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m;
int p[100000002];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> v;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            v.push_back(p[i] + p[j]);
        }
    }
    int ans = 0;
    sort(v.begin(), v.end());
    cout << endl;
    for (int i = 0; i <= v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= v.size(); i++) {
        int nokori = m - v[i];
        auto it = lower_bound(v.begin(), v.end(), nokori);
        int sum = *it + v[i];
        ans = max(ans, *it + v[i]);
        cout << "nokori = " << nokori << ", v = " << v[i] << ", sum = " << sum
             << endl;
    }
    cout << ans << endl;
    return 0;
}
