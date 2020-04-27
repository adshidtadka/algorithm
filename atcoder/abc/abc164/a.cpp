#include <iostream>

using namespace std;

int s, w;

int main(int argc, char const *argv[]) {
    cin >> s >> w;
    if (w >= s) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
    return 0;
}
