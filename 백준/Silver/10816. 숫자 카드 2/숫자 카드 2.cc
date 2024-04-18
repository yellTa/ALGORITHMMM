#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >> n;
    int A[n];
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    sort(A,A+n);
    int m; cin>>m;

    for(int i=0; i<m; i++) {
        int find; cin >>find;

        cout << upper_bound(A, A+n, find) - lower_bound(A, A+n, find) << " ";

    }

}



