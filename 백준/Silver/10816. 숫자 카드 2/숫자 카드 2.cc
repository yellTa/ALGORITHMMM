#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>

using namespace std;

//이분탐색 풀이
int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;
    int A[n];
    for(int i=0; i< n; i++) {
        cin>>A[i];
    }

    //sort 이분탐색을 위한 정렬
    sort(A, A+n);

    int m ; cin >>m;
    map<int,int> B;
    for(int i=0; i<m; i++) {
        int x; cin >>x;
        cout << upper_bound(A,A+n,x) - lower_bound(A, A+n,x)<<" ";
    }

}
