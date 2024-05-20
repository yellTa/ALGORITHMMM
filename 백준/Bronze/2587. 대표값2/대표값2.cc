
#include <iostream>
#include <list>
#include <algorithm>
/*
[문제]
다섯개의 자연수가 주어질 떄 평균과 중앙값을 구해라

[입력]
5개의 수 "\n"과 함께
n은 10의 배수
10<=n<=100

[출력]
첫째줄 : 평균
둘째 줄 : 중앙값

[IDEA]
평균 : 다 더하고 /5
중앙값 : 정렬후 index2번

값 받으면서 동시에 sum구하기
배열에 넣어서 정렬해서 중앙값 구하기
* */
using namespace std;

int main() {

    int sum=0;
    int a[5];
    for(int i=0; i<5; i++) {
        int x; cin >> x;
        a[i] = x;
        sum +=x;
    }

    int avg = sum/5;
    sort(a, a+5);
    int mid = a[2];
    cout << avg << "\n"<< mid;

}