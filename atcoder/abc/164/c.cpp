#include <iostream>
#include <set>

using namespace std;

int n;
set<string> gifts;

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        gifts.insert(s);
    }
    cout << gifts.size() << endl;
    return 0;
}
