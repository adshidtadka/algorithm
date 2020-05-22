// c
#ifndef _glibcxx_no_assert
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

#ifdef gxx_experimental_cxx0x
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// c++
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

#ifdef gxx_experimental_cxx0x
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
using p = pair<int, int>;

int n;
ll h[100001], s[100001];

bool isok(ll x) {
    ll timetable[n];
    memset(timetable, 0, sizeof(timetable));
    for (int i = 0; i < n; i++) {
        ll between = x - h[i];
        if (between < 0) return false;
        int cnt = between / s[i];
        if (cnt >= n) cnt = n - 1;
        while (timetable[cnt] == 1) {
            cnt--;
            if (cnt < 0) {
                return false;
            }
        }
        timetable[cnt] = 1;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> s[i];
    }
    ll inf = 1000;
    ll right = inf;
    ll left = 0;
    ll middle = inf / 2;
    while (true) {
        if (isok(middle)) {
            right = middle;
        } else {
            left = middle;
        }
        middle = (right - left) / 2 + left;
        if (right == left) {
            cout << right << endl;
            return 0;
        } else if ((right - left) == 1) {
            if (isok(right)) {
                cout << right << endl;
                return 0;
            } else {
                cout << left << endl;
                return 0;
            }
        }
    }
    return 0;
}
