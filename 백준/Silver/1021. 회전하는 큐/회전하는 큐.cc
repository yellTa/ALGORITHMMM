#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int num2(deque<int> dq, int find) {

    int cnt =0;
    while(1) {
        if(dq.front() != find) {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt +=1;
        }else {
            dq.pop_front();
            return cnt;
        }
    }
}

int num3(deque<int> dq, int find) {
    int cnt =0;

    while(1) {
        if(dq.front() != find) {
            dq.push_front(dq.back());
            dq.pop_back();
            cnt +=1;
        }else {
            dq.pop_front();
            return cnt;
        }
    }

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

   int n,m; cin >> n >>m;

    int A[m];
    for(int i=0; i<m; i++) {
            cin >> A[i];
    }

    deque<int> dq;
    int answer=0;
    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }

    for(int i=0; i<m; i++) {
            int x =num2(dq,A[i]);

            int y =num3(dq,A[i]);


        // cout << x <<" : "<< y << "\n";
        if(x<y) {
            //2번연산이 작은 경우
            answer +=x;
            //2번 연산 수행
            while(1) {
                if(dq.front() != A[i]) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }else {
                    dq.pop_front();
                    break;
                }
            }
        }else {
            answer +=y;
            while(1) {
                if(dq.front() != A[i]) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }else {
                    dq.pop_front();
                    break;
                }
            }
        }
    }

    cout<< answer;

}
