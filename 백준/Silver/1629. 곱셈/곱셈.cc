#include <queue>
#include <iostream>

using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m) {
    if(b==1) return a%m;
    ll val = POW(a,b/2,m);
    val = val*val%m;

    if(b%2==0) return val;
    return val*a%m;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    //재귀를 이용해서 코드 짜기
    //1부터 n까지 출력 재귀
    // sum(1,10);
    // 덧셈 재귀
    ll a,b,c; cin >> a >> b>> c;

    cout << POW(a,b,c);

}