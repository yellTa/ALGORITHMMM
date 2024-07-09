#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int value[10];
int arr[10];
bool isused[10];

void func(int x) {
    if(x == m) {
        for(int i=0; i< m; i++) {
            cout << value[arr[i]]<< " ";
        }
        cout << "\n";
        return;
    }

    int st =0;
    if(x !=0) st = arr[x-1];
    for(int i=st; i<n; i++) { //인덱스
            arr[x] = i;
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
