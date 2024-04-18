#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
bool cmp(string a, string b) {
    if(a.length() == b.length()) return a<b; //길이 같으면 사전순
    else return a.length() < b.length(); //길이 다르면 짧은 것 부터
}


int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    //vector에 넣고 sort를 돌리는 방법도 있다.
    //그럼 문제에서 원하는대로 정렬해줌
   int n ;cin>>n;

    string A[n] = {};
    for(int i=0; i< n; i++) {
        cin >> A[i];
    }

    sort(A, A+n, cmp);
    for(int i=0; i< n ;i++) {
        if(i !=0 && A[i] == A[i-1]) {
            continue;
        }
        cout << A[i] <<"\n";
    }

}
