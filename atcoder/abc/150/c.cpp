#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n, m;
int a[100001];

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a + b / gcd(a, b);
}



int main() {
    cin >> n >> m;
    for(int i; i < n; i++) {
        cin >> a[i];
    }
    
    return 0;
}
