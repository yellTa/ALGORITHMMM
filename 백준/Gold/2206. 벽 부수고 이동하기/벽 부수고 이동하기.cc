#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second
/*
 * 벽을 하나씩 부순 bfs의 결과를 vector에 담아서 return
 * 위치 0,0에서 n-1,m-1까지
 * 1. 원본, 벽을 부순 bfs 보드 준비하기 2차원 vector에 해당 값을 담기
 * 2. 각각 bfs 수행해서 결과를 vector에 담기
 * 3. vector정렬하기
 * 4. size가 0이면 -1출력 1이상인경우 제일 작은 값을 출력한다.
 *
 */
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char board[1000][1000];
int dist[1000][1000][2];

// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함

int N, M;

int bfs() {
    //초기화 작업
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            dist[i][k][0] = dist[i][k][1] = -1;
        }
    }

    dist[0][0][0] = dist[0][0][1] = 1; //시작점 등록
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while(!q.empty()) {
        int x,y,broken;
        tie(x,y,broken) = q.front();
        if(x == N-1 && y ==M-1) return dist[x][y][broken];

        int nextdist = dist[x][y][broken]+1;
        q.pop();

        for(int dir =0; dir<4; dir++) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx<0 || nx>= N || ny<0 || ny>= M)continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken]==-1) {
                dist[nx][ny][broken] = nextdist;
                q.push({nx,ny,broken});
            }

            //nx ny 를 부수는 경우
            //부쉈을 때 도달할 수 있는 거리의 정보를 dist[x][y][1] 에 담는다.
            //이 자리는 원래 벽이었떤 자리고 벽이 없으면 몇 번만에 도달할 수 있는 지 나타낸다.
            //!borken -> broken==0 인경우에만 즉 부서지지 않은 경우에만 해당 코드를 실행하게 해
            // broken==1인 상태에서는 아래 코드가 수행되지 않는다.-> 벽을 부술 수 없는 경우를 의미한다.
            // 따라서 q에 push되지 않는다.
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][broken] ==-1) {
                dist[nx][ny][1]  = nextdist;
                q.push({nx,ny,1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    //board받기
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];
        }
    }

    // for (int height = 0; height < N; height++) {
    //     for (int width = 0; width < M; width++) {
    //         cout << board[height][width];
    //     }
    // cout << "\n";
    // }


    cout << bfs();

    return 0;
}
