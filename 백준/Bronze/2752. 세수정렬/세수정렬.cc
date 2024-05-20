
#include <iostream>
#include <list>
#include <algorithm>
/*
[문제]
정수 세 개가 주어짐, 가장 작은수 ,그 다음수, 가장 큰 수를 출력해라

[입력]
정수 세 개 1<= N< = 10^7

[조건]
O(n)으로 풀어야 함

[IDEA]
배열에 정수 세개를 넣어서 정렬하면 될듯
이때 정수 세개는 double형으로 10 ^15까지 보장
* */
using namespace std;

int main() {

    double store[3];
    for(int i=0; i<3; i++) {
        int x; cin >>x;
        store[i] = x;
    }
    sort(store, store+3);

    for(double x : store) {
        cout << to_string((int)x) << " ";
    }
}