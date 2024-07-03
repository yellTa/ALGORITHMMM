#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int A[21];

void reverse(int a, int b) {
    for(int i=0; i < (b-a+1)/2; i++) {
        swap(A[a+i], A[b-i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);


    for(int i=1 ;i<21; i++)A[i] =i;

    for(int i=0 ;i<10; i++) {
        int a, b; cin >>a>>b;

        //역순 배치 로직
        //1. 역배치 배열만들기
        reverse(a,b);
    }
    for(int i=1; i<21; i++)cout << A[i] << " ";

}
