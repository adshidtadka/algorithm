#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int repNum = 3;

void dfs(int index, vector<int> v) {
    if (v.size() == repNum) {
        for (int i = 0; i < repNum; i++) {
            cout << v[i] << ",";
        }
        cout << endl;
        return;
    }
    vector<int> v0 = v;
    vector<int> v1 = v;
    v0.push_back(0);
    v1.push_back(1);
    dfs(index + 1, v0);
    dfs(index + 1, v1);
}

int main(int argc, char const *argv[]) {
    vector<int> v;
    dfs(0, v);
    return 0;
}
