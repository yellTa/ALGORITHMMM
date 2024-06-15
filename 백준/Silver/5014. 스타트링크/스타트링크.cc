#include <iostream>
#include <algorithm>
#include <queue>

/*
 * F층으로 이루어진 고층 건물 스타트 링크는 G층 강호는 지금 S층
 * U 위로감 D 아래로 감
 *
 *F ,S ,G, U ,D
 *최고층, 현재 위치 ,목표층 ,up ,down
 *10 1 10 2 1
 *10층으로 이루어짐
 *강호는 1층
 *스타트링크는 10층(도착지)
 * u 2번
 *D 1번
 *
 *
 */
using namespace std;
int F, S, G, U, D;
int dist[1000002];

int main() {

    cin >> F >> S >> G >> U >> D;

    fill(dist+1, dist+F+1, -1);

    queue<int> q;
    dist[S]=0;
    q.push(S);

    while (!q.empty()){
        int cur = q.front();q.pop();

        for(auto nxt : {cur+U, cur-D}) {
            if(nxt>F || nxt<=0 || dist[nxt] !=-1)continue;
            dist[nxt] = dist[cur] +1;
            q.push(nxt);
        }
    }
    if(dist[G] == -1) {
        cout << "use the stairs";
    }else cout << dist[G];
    return 0;
}
