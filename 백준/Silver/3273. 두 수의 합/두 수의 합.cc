#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;
    int N[n];

    int A[2000001];
    fill (A, A+2000001, 0);

    // 배열 받기
    for(int i=0; i< n; i++) {
         cin >>N[i];
        A[N[i]] =1;
    }

    int x; cin >>x;

    int answer =0;
    for(int i=0; i< n; i++) {
        int index = x - N[i];
        if(index != N[i] && index >=0 && A[index] ==1) answer ++;
    }

    cout << answer/2;

    return 0;
}
