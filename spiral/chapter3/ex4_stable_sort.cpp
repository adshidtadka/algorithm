#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Card {
    char suit;
    int value;
};

int n;
Card c1[101], c2[101];

void bubbleSort(Card x[], int y) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = y - 1; j > 0; j--) {
            if (x[j].value < x[j - 1].value) {
                swap(x[j], x[j - 1]);
                flag = 1;
            };
        }
    }
}

void selectionSort(Card x[], int y) {
    for (int i = 0; i < y; i++) {
        int minj = i;
        for (int j = i; j < y; j++) {
            if (x[j].value < x[minj].value) {
                minj = j;
            }
        }
        if (x[i].value != x[minj].value) {
            swap(x[i], x[minj]);
        }
    }
}

bool isStable(Card bubble[], Card select[], int x) {
    for (int i = 0; i < x; i++) {
        if (bubble[i].suit != select[i].suit) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c1[i].suit >> c1[i].value;
        c2[i] = c1[i];
    }
    bubbleSort(c1, n);
    selectionSort(c2, n);
    bool stable = isStable(c1, c2, n);
    rep(i, n - 1) cout << c1[i].suit << c1[i].value << " ";
    cout << c1[n - 1].suit << c1[n - 1].value << endl << "Stable" << endl;
    rep(i, n - 1) cout << c2[i].suit << c2[i].value << " ";
    cout << c2[n - 1].suit << c2[n - 1].value;
    if (stable) {
        cout << endl << "Stable" << endl;
    } else {
        cout << endl << "Not stable" << endl;
    }
    return 0;
}
