#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int vis[1000001];
int dx[] = {-1, 0 ,1};
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,k; cin >>n>>k;

    int answer=0;

    if(n>k) {
        answer = n-k;
        cout << answer;
        return 0;
    }else if(n ==k ) {
        cout << 0;
        return 0;
    }else if(n<k) {
        queue<int> Q;
        Q.push(n);
        int acycle=1;
        int size = Q.size();
        int cycle =0;

        while(!Q.empty()) {
            answer  = Q.front(); Q.pop();

            if(answer -1 >0 && vis[answer -1] ==0) {
                Q.push(answer-1);
                vis[answer -1] =1;
            }
            if(answer +1 <1000001 && vis[answer +1] ==0) {
                Q.push(answer +1);
                vis[answer+1] =1;
            }
            if(answer *2 <1000001 && vis[answer *2] ==0) {
                Q.push(answer*2);
                vis[answer*2] =1;
            }

            if(answer +1 ==k ||  answer -1 ==k || answer  *2 == k) {
                cout << acycle;
                break;
            }
            cycle +=1;
            if(size == cycle) {
                cycle =0;
                size = Q.size();
                acycle +=1;
            }
        }
    }
    return 0;
}
