#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int n,m;
int arr[10];// 선택한 숫자를 저장하는 배열
bool isused[10]; //숫자가 이미 선택되언쓴지 여부를 저장하는 배열

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++)cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int st =1;
    if(k!=0)st = arr[k-1];
    //i가 의미하는 것
    for(int i=st; i<=n; i++) {
            arr[k] = i;
            func(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;
    func(0);

}
