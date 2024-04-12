#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>

using namespace std;


int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;
    map <int,int>A;
    for(int i=0; i< n; i++) {
        int a; cin >>a;
        A[a]++;
    }


    int m ; cin >>m;
    map<int,int> B;
    for(int i=0; i<m; i++) {
        int x ;
        cin >>x;
        cout << A[x]<<" ";
    }

}
