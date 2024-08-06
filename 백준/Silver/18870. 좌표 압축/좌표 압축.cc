#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;
int arr[1000010];
int delmulti[1000010];

int answer[1000010];
int n;

int delMulti() {
    int idx=1;
    delmulti[0] = arr[0];

    for(int i=01; i<n; i++) {
        if(arr[i] != arr[i-1]) {
            delmulti[idx++] = arr[i];
        }
    }

    return idx;
}

int findValueIdx(int x, int len) {
    int st =0;
    int en = len-1;

    while(st<=en) {
        int mid = (st+en)/2;
        if(delmulti[mid]<x)st = mid+1;
        else if(delmulti[mid]>x) en= mid-1;
        else return mid;
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>n;
    for(int i=0; i<n; i++) {
        cin>> arr[i];
        answer[i] = arr[i];
    }
    sort(arr, arr+n);
    int len = delMulti();

    for(int i=0; i<n; i++) {
        cout << findValueIdx(answer[i],len);
        if(i<n-1) cout << " ";
    }
}
