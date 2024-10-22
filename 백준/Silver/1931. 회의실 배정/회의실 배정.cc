#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*시작시간 끝나는 시간
 *회의가 겹치지 않게 하면서 회의실을 사용할 수 있는
 *회의의 최대 갯수를 찾아보기
 *회의는 한번 시작하면 중단 X
 *회의가 끝남과 동시에 다음 회의가 시작 가능
 *시간 시간과 끝나는 시간이 같다 -> 시작하자마자 긑ㄴ난다ㅗㄱ 생각
 *
 *N< 10^6 시작 시간과 끝나는 시간은 int범위
 *
 *키워드 : 최대 갯수를 찾아보자 -> 회의를 가장 많이 할 수 있는 경우(회의시간이 가장 짧은 경우)
 *
 *
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n; cin>> n;
    vector<pair<int,int>> A;
    for(int i=0; i<n; i++) {
        int x,y;
        cin>> x>>y;
        A.push_back({x,y});

    }
    sort(A.begin(), A.end(),[](pair<int,int> &a, pair<int,int> &b) {
        if(a.second == b.second) {
            return a.first<b.first;//끝점이 같으면 시작 시간이 빠른거
        }
        return a.second< b.second; //아니면 끝점이 작은거
    });

    int answer=1;
    int end = A[0].second;

    for(int i=1; i<n; i++) {
        if(end > A[i].first) continue;
        answer++;
        end = A[i].second;
    }

    cout << answer;

    return 0;
}