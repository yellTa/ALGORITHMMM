
#include <iostream>
#include <list>
#include <algorithm>
/*
[문제]
7개의 자연수
홀수인 자연수를 골라 합을 구함
고른 홀수들 중 최솟값을 찾아라

[입력]
1<=n<=100
7개의 자연수가 \n으로 주어짐

[출력]
더한 홀수
최소 홀수

홀수가 존재하지 않으면 첫째 줄에 -1출력
[IDEA]
값 받기
정렬하기
홀 수 찾기(제일 처음 홀수가 최솟 값임 count인자를 주고 1인경우에만 수행하자)
홀수 찾으면서 더하기

* */
using namespace std;

int main() {

    int a[7];
    for(int i=0; i<7;i++) {
        int x; cin >>x;
        a[i] =x;
    }

    sort(a,a+7);

    int count =0;
    bool flag=0;
    string answer="";

    int sum=0;
    int min=0;
    for(int i=0; i<7; i++) {
        if(a[i] %2 ==1){
            flag=1;
            sum += a[i];
            count++;
            if(count ==1) {
                min = a[i];
            }
        }
    }
    if(!flag)cout << -1;
    else cout << sum <<"\n"<< min;

}