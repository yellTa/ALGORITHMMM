#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[20];
int value[20];
int isused[20];

void func(int k) {
    //k가 의미하는건 depth이다.
    if (k == m) {
        for (int i = 0; i < m; i++)cout << value[arr[i]] << " ";
        cout << "\n";
        return;
    }

    int st=0;
    int temp=0;

    for (int i = st; i < n; i++) {
        if(!isused[i] && temp != value[i]) {
            isused[i]=1;
            arr[k] = i;
            temp= value[arr[k]];
            func(k + 1);
            isused[i] =0;
        }

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    sort(value, value + n);

    func(0);
}
