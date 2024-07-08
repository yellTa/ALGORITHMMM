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
int arr[10];// 숫자
bool isused[10]; //수를 사용했는지 안했는지

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++)cout << arr[i]<< " ";
        cout << "\n";
        return;
    }

    //n의 수 만큼 반복
    for(int i=1; i<=n ; i++) {
        if(isused[i] == 0) {
            isused[i] = 1;
            arr[k] = i;
            func(k+1);
            isused[i] = 0;
        }

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;

    func(0);
}
