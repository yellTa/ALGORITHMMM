#include <iostream>
#include <algorithm>;
#include <queue>;
#include <cstdlib>
using namespace std;

int store[2000002];
/*
 *[문제]
 * N개의 수가 주어졌을 때, 비 내림차순으로 정렬
 *길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
 *
 *[입력]
 *수의 개수 1<= N<=10^6
 *둘쨰줄부터 N개의 줄까지 숫자
 *
 *-10^6<= 숫자<=10^6
 * 같은 수가 여러번 중복될 수 있음
 *
 *
 */
int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;
    while(n--) {
        int x; cin >>x;
        x = x+1000000;
        store[x] +=1;
    }


    for(int i=0; i< 2000001; i++) {
        if(store[i] !=0) {
            while(store[i] !=0) {
                cout << i-1000000 << "\n";
                store[i] -=1;
            }
        }
    }
}
