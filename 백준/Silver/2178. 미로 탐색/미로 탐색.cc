#include <queue>
#include <iostream>

#define X first
#define Y second

using namespace std;

int board[101][101];
int vis[101][101];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m; cin >>n>>m;

    for(int i=1; i<=n; i++) {
        string s; cin >>s;
        for(int k=1; k<=m; k++) {
            board[i][0] = 0;
            board[i][k] =s[k-1] -'0';
        }
    }

    //bfs 초기작업
    vis[1][1] = 1;
    queue<pair<int,int>> q;
    q.push({1,1});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y +dy[i];

            if(nx <1 || nx>n || ny <1 || ny>m)continue;
            if(board[nx][ny] ==0 || vis[nx][ny])continue;

            if(nx == n && ny ==m) {
                cout << vis[cur.X][cur.Y]+1;
                return 0;
            }
            q.push({nx,ny});
            vis[nx][ny] =vis[cur.X][cur.Y]+1;
        }
    }
}