#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int newN;
int arr[10];
int num[10];
bool isused[10];

void func(int x) {
    if(x==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp=0;
    for(int i=0; i<n; i++) {
        if(!isused[i] && tmp !=num[i]) { //이전 수열의 마지막 항과 새로운 수열의
            //마지막 항이 같으면 중복 수열
            isused[i] = true;
            arr[x] = num[i];
            tmp = arr[x];// 마지막으로 저장된 값 저장
            func(x+1);// 다음 작업 시작
            isused[i] =false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }

    sort(num, num+n);

    func(0);


}
