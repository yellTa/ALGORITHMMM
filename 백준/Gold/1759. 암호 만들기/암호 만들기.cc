#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int l, c;
char hint[20];
int arr[20];
int isused[20];

bool check() {
    int m=0;
    int j=0;

    string s;
    for (int i = 0; i < l; i++) {

        if (hint[arr[i]] == 'a' || hint[arr[i]] == 'i' ||
            hint[arr[i]] == 'e' || hint[arr[i]] == 'o' || hint[arr[i]] == 'u') {
            m++;
        } else j++;
        s +=hint[arr[i]];
    }
    if (m >= 1 && j >= 2) return true;

    return false;
}


void func(int k) {
    if (k == l) {
        if (check()) {
            for (int i = 0; i < l; i++)cout << hint[arr[i]];
            cout << "\n";
        }
        return;
    }

    int st = 0;
    if (k != 0)st = arr[k - 1] + 1;

    for (int i = st; i < c; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            arr[k] = i;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> hint[i];
    }

    sort(hint, hint + c);
    func(0);
}
