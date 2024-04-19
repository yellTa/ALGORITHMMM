#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    cin >> n;

    queue<int> A;
    // priority_queue<int> R; // 우선순위큐는 높은순에서 낮은 순으로 정렬해준다.
    priority_queue<int, vector<int>, greater<int> > R;
    stack<int> O;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push(x);
        R.push(x);
    }

    while(!R.empty()) {
        int flag = 3; // 수행된 부분이 있으면 즉 R이 빠져가나는 부분이 있으면 1로 변경해준다.

        if(!A.empty()) {
            while(A.front() !=R.top()) {
                int x =A.front();
                O.push(x);
                A.pop();
                flag =1;
                if(A.empty()) break;
            }

            if(!A.empty()&& A.front() == R.top()) {
                flag =1;
                A.pop();
                R.pop();
            }
        }

        if(!O.empty()) {
            while(R.top() ==O.top()) {
                O.pop();
                R.pop();
                flag =1;
                if(O.empty()) break;
            }
        }

        if(flag ==3) {
            cout << "Sad" ; return 0;
        }

    }
    cout << "Nice";
    return 0;
}
