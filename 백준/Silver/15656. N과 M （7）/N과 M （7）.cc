#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int value[10];
int arr[10];
bool isused[10];

void func(int x) {
    if(x == m) {
        for(int i=0; i<m; i++)cout << value[arr[i]] <<" ";
        cout << "\n";
        return;
    }

    for(int i=0; i < n; i++) {
            arr[x] = i; //arr에 인덱스의 값을 저장한다. value에서 뽑아낼 index값을 추출하는 것
            func(x+1);

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++)cin>> value[i];

    sort(value, value+n);

    func(0);


}
