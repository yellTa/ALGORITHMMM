#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    cin >> n;

    int cnt=1;
    stack<int> O;
    while(n--) {
        int T; cin >>T;
        if(T == cnt) cnt++; // 현재 순번과 일치한다면 보내주기
        else O.push(T); // 아니면 스택에서 기다리기

        while(!O.empty() && O.top() == cnt) {
            O.pop();// 스택 맨 위가 현재 순번과 일치한다면 보내주기
            cnt++;
        }
    }

    if(O.empty()) cout<< "Nice";
    else cout <<"Sad";

}
