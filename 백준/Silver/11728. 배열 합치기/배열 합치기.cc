#include <iostream>
#include <algorithm>

using namespace std;
/*
 *
 *[문제]
 *배열을 합친 다음 정렬해서 출력하는 프로그램을 작성
 *
 *
 * [입력]
 * 주어지는 배열은 이미 정렬되어 있다.
 * 배열 A의 크기 N, 배열 B의 크기 M (1 <= N,M<=10^5)
 * 배열의 들은 수는 int보다 작음
 */


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m; cin>> n >>m;

    int A[n];
    int B[m];
    for(int i=0; i<n; i++) {
        cin>> A[i];
    }
    for(int j=0; j<m; j++) {
        cin >> B[j];
    }

    int c[n+m];

    int aidx = 0; int bidx=0;
    for(int i=0; i<n+m; i++) {
        if(bidx==m) c[i] = A[aidx++];
        else if(aidx ==n)c[i] = B[bidx++];
        else if(A[aidx] <= B[bidx]) c[i] = A[aidx++];
        else c[i] = B[bidx++];

    }

    for(int x : c) cout << x<< " ";

    return 0;
}