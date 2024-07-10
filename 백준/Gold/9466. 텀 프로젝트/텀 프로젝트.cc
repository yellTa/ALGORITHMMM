#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
//배열을 저장할 때에는 꼭 범위를 지정해주자
int wantTeam[1000005];
int status[1000005];


void search(int i) { //i 번째 사람 검사
    int cur  = i;
    //i번이 지시하는 사람을 넣는다.
    while(true) {
        status[cur] = i; //시작 사람을 넣는다?
        cur = wantTeam[cur];

        if(status[cur] ==i) {
            while(status[cur] !=0) {
                status[cur] = 0;
                cur = wantTeam[cur];
            }
            return;
        }

        else if(status[cur] !=-1)return;

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin>>tc;
    while(tc--) {
        cin>>n;
        //초기화 작업
        for(int i=1; i<= n; i++) {
            cin >> wantTeam[i];
        }

        //기본값 -1 -> 검사하지 않은 사람
        fill(status+1, status+n+1,-1);

        for(int i=1; i<=n ;i++) {
            if(status[i] == -1) {//검사 수행
                search(i);
            }
        }

        int cnt=0;
        for(int i=1; i<=n; i++) {
            if(status[i] !=0)cnt ++;
        }

        cout << cnt<< "\n";
    }


}
