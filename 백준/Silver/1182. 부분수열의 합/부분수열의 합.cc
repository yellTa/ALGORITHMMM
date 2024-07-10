#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n,s;

int value[30];

bool isused[30];
int arr[30];

int cnt=0;

void func(int k, int sum) {
    if(k==n) {
        if(sum==s)cnt++;
        return;
    }

    func(k+1, sum);
    func(k+1, sum+value[k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n >>s;

    for(int i=0; i<n; i++)cin>> value[i];

    func(0,0);
    if(s==0)cnt--;
    cout << cnt;

}
