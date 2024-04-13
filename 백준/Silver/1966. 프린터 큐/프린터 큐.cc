#include<map>
#include<algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n, m;
        cin >> n >> m;
        queue<int> Q; // docs queue
        queue<int> B; // bool queue

        int A[n]; // A[]는 오름차순 정렬 배열

        //값 초기화
        for (int i = 0; i <n; i++) {
            int x; cin >> x;

            A[i] = x;
            Q.push(x);

            if (i == m) {
                B.push(1);
            } else {
                B.push(0);
            }
        }

        //우선순위 큐를 쓰면 자동으로 정렬해준다...
        sort(A, A + n, cmp);


        int cnt =0;
        for(int i=0; i<n; i++) {
            while(true) {
                if(A[i] != Q.front()) {
                    int tempQ = Q.front();
                    Q.pop();
                    Q.push(tempQ);

                    int tempB = B.front();
                    B.pop();
                    B.push(tempB);

                }else if(A[i] == Q.front()) {
                    cnt +=1;
                    break;
                }
            }

            if(B.front() == 1) {
                break;
            }
            Q.pop();
            B.pop();

        }
        cout << cnt <<"\n";

        // for (int i = 0; i < n; i++) {
        //     cout << Q.front() << " ";
        //     Q.pop();
        // }
        // cout << "\n";
        // for (int i: A) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << B.front() << " ";
        //     B.pop();
        // }
    }
}
