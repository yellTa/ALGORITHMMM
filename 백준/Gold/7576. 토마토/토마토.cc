#include <queue>
#include <cmath>
#include <iostream>

#define X first
#define Y second

using namespace std;

int board[1001][1001];
int vis[1001][1001];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int m,n; cin >> m >>n;

    queue<pair<int,int>> q;
    bool flag = false;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            int x; cin >>x;
            if(!x) {
                board[i][k] =0;
                vis[i][k]=0;
                flag = true;
                continue;
            }

            if(x==1) {
                q.push({i,k});
                board[i][k] =1;
                vis[i][k] =1;
                continue;
            }
            if(x== -1) {
                board[i][k] = -1;
                vis[i][k] = -1;
            }

        }
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx <0 || nx>=n || ny <0 || ny>=m)continue;
            if(vis[nx][ny] || vis[nx][ny] ==-1)continue;
            q.push({nx,ny});
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
        }
    }
    if(!flag) {
        cout << 0;
        return 0;
    }

    int max =0;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            if(max < vis[i][k])max = vis[i][k];
            if(vis[i][k]==0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << max-1;

}