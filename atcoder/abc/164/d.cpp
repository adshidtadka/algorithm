#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> vec;

int main(int argc, char const *argv[]) {
    cin >> s;
    int ans = 0;
    for (int i = 1; i < 10000; i++) {
        string::size_type pos = to_string(i * 2019).find("0");
        if (pos == string::npos) {
            vec.push_back(to_string(i * 2019));
        }
    }
    for (string v : vec) {
        string::size_type pos = s.find(v);
        while (pos != string::npos) {
            ans++;
            pos = s.find(v, pos + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
