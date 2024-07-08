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
int arr[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i< m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {
        if(!isused[i]) { // i를 사용하지 않은경우
            arr[k] =i; // k 번째 수를 i로 정하기
            isused[i] =1; // i번째 수를 사용했다고 표시하기
            func(k+1); // 다음 수를 정하려고 한 단계 들어가기
            isused[i] =0; // 그 다음 i사용안했다고 하기4 1 |4 2 |4 3 뒤에 1,2,3의 경우를
            //구해야하기 떄문 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;
    func(0);
}
