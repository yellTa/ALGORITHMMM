#include <iostream>
#include <algorithm>


using namespace std;

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;

    int A[n];

    for(int i=0; i< n; i++) {
        cin >> A[i];
    }

    sort(A, A+n);
    for(int i=0; i<n; i++) {
        cout << A[i]<<" ";
    }


    return 0;
}


