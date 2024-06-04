#include <iostream>
#include <algorithm>;
#include <queue>;
#include <cstdlib>
#include <vector>
using namespace std;

/*
 *[문제]
 *준규가 가장 많이 가지고 있는 숫자를 적는다.
 *
 *[입력]
 *1<= N <= 100000
 * [IDEA]
 * 정렬 한다.
 * 수를 index로 사용하고 ++한다. 범위는 long long으로 한다.
 */

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;
    long long store[n];
    for(int i=0; i<n; i++) {
        cin >> store[i];
    }

    sort(store, store+n);

    long long maxval =-(111<<62)-1;
    int maxcnt=0;
    int cnt=1;

    for(int i=1; i<=n; i++) {
        if(store[i] !=store[i-1]) {
            if(cnt>maxcnt) {
                maxcnt = cnt;
                maxval = store[i-1];
            }
            cnt=1;
        }else cnt++;
    }

    cout << maxval;
}
