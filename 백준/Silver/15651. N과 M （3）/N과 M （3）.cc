#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++)cout << arr[i] << " ";
        cout << "\n";
        return;
    }


    //i가 의미하는 것 들어가는 값
    for(int i=1; i<=n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;
    func(0);

}
