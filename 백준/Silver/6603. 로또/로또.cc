#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;

int lottery[15];
int arr[15];//lottery의 index를 저장
int isused[15];

void func(int k) {
    if(k==6) {
        for(int i=0; i<6; i++)cout << lottery[arr[i]]<< " ";
        cout << "\n";
        return;
    }

    int st=0;
    if(k!=0) st = arr[k-1]+1;
    for(int i=st; i<n; i++) {
        if(!isused[i]) {
            isused[i] =1;
            arr[k] = i;
            func(k+1);
            isused[i] =0;
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >>n;
        if(n==0)return 0;

        for(int i=0; i<n; i++)cin >> lottery[i];

        func(0);

        cout << "\n";
    }
}
