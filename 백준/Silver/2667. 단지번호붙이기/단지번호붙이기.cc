#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
/*단지 동서남북
 *[문제]
 *단지에 해당하는 '집의 수를' 오름차순으로 정렬하여 출력
 *단지번호 순이 아니라 '집의 수'를 오름차순으로 정렬하여 출력하는 것
 *
 *연결되었다는 것은 동서남북을 의미한다.
 *
 *[IDEA]
 *모든 graph를 다 돌면서 단지가 시작 되는 곳을 찾는다.
 *거기서 부터 BFS시작(1단지.. 2단지.. 3단지...)
 *BFS를 다 수행하고 queue에 push된 횟수 == bfs가 탐색한 수 vector에 넣는다.
 *모든 BFS룰 수행하고 단지수를 오름차순으로 정렬하여 출력한다.
 *
 *[필요한 것]
 *단지 graph 2차원 배열
 *비어있는 vis 2차원 배열
 *
 *집의 수가 들어있는 house vector(house vector는 정렬되어야 한다.)
 *총 단지의 수 = house vector의 size
 *
 *[제한사항]
 * 5<=n <=25
 *
 *
 */
int graph[26][26];
int vis[26][26];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
    int n;
    cin >> n;
    //단지 graph받기
    for(int h =0; h< n; h++) {
        string s; cin>>s;
        for(int w=0; w<n; w++) {
            char c =s[w];
            graph[h][w] = c -'0';
        }
    }

    //house vector 생성
    vector<int> house;
    //모든 그래프를 다 돌면서 단지가 있는 시작점을 찾고 BFS수행
    for(int h =0; h< n; h++) {
        for(int w=0; w<n; w++) {
            if(graph[h][w] == 1 && vis[h][w] ==0) {// 시작점 그리고 vis에서 방문하지 않은 노드
                //bfs를 수행하기
                vis[h][w] =house.size()+1;
                queue<pair<int,int>> q;
                q.push({h,w});

                int houseCnt=1;

                while(!q.empty()) {
                    auto cur = q.front(); q.pop();

                    for(int dir =0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
                        if(vis[nx][ny] >=1 || graph[nx][ny]==0)continue; //이미 방문한 곳 or 집이 아닌 곳

                        houseCnt++;
                        vis[nx][ny] = house.size()+1;
                        q.push({nx,ny});
                    }
                }

                house.push_back(houseCnt);
            }
        }
    }

    // for(int i=0; i<n ;i++) {
    //     for(int k=0; k<n; k++) {
    //         cout << vis[i][k] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << house.size()<<"\n";
    sort(house.begin(), house.end());
    for(int houseCnt : house)cout << houseCnt <<"\n";

}
