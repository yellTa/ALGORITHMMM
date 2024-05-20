#include <iostream>
#include <list>
#include <algorithm>
/*[문제]
 * 두 수 사이에 있는 정수를 모두 출력하는 프로그램
 *
 * [입력]
 * 두 정수 A, B
 *
 *
 *[출력]
 * 두 수 사이에 있는 수의 개수를 출력한다.
 * 그리고 수들을 출력함 A B C D ->이런 형식

 * [조건]
*  1<=A,B<=10^15
*  A,B가 같은 경우도 존재한다. 기억하자
* [IDEA]
* 조건에서 주어진 A,B의 사이값은 dobule범위
*
 */
using namespace std;

int main() {
    double a, b;
    cin >> a>> b;


    if (a > b) swap(a,b);
    if (a == b || b - a == 1) cout << 0;
    else {
        cout << b-a-1<<"\n";

        for(double i=a+1; i<b;i++) {
            string s = to_string(i);
            int x = s.find('.');
            string a = s.substr(0,x);
            cout << a <<" ";
        }

    }


}
