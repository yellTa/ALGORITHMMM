#include <iostream>
#include <algorithm>

using namespace std;
int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int c;  cin >> c;

    int arr[10001]={};
    for(int i=0; i <c; i++) {
        int d; cin>>d;
        arr[d] +=1;
    }

    for(int i=0;i <10001; i++) {
        while(arr[i] !=0) {
            cout << i <<"\n";
            arr[i] -=1;
        }

    }

    return 0;
}