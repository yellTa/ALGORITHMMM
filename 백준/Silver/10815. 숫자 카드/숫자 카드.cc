#include <iostream>
#include <algorithm>

using namespace std;

int search(int A[], int find ,int n) {
    int start=0;
    int end=n-1;
    int mid=0;

    while(start<=end) {
        mid = (start + end)/ 2;

        if(A[mid] == find) return 1;
        else if(A[mid] < find) start = mid+1;
        else if(A[mid] > find) end = mid-1;
    }
    return 0;
}
int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >> n;

    int A[n]={};
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    sort(A, A+n);

    int m; cin>>m;
    int B[m]={};
    for(int i=0; i< m; i++) {
        cin >> B[i];
    }


    for(int i=0 ; i< m; i++){
        cout << search(A, B[i],n) << " ";
    }

    return 0;
}