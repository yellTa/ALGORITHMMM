#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m; cin >> n >>m;

    int store[n];
    for(int i=0; i<n; i++) {
        int x; cin >>x;
        store[i] =x;
    }

    sort(store, store+n);

    int max=0;
    for(int i=0; i<n-2; i++) {
        for(int k=i+1; k<n-1; k++) {
            for(int j=k+1; j<n; j++) {
                
                int x = store[i] + store[k] + store[j];
                if(x<=m && max<x)max = x;
            }
        }
    }
    cout << max;

}