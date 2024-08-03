#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;
int arr[100000];
int N;
int M;

int find(int x) {
    int st = 0;
    int en =N-1;

    while(st<=en) {//st가 커지는 순간 종료
        int mid = (st+en)/2;
        if(arr[mid]<x) {
            st = mid+1;
        }else if(arr[mid]>x) {
            en = mid-1;
        }else return 1;

    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>N;
    for(int i=0; i< N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    cin >> M;
    for(int i=0; i< M; i++) {
        int x ; cin>>x;

        cout << find(x)<< "\n";
    }

}
