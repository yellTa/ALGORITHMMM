#include <iostream>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>

#define X first //세로
#define Y second //가로

using namespace std;

int vis[301][301];

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int x, int y, int b, int destX, int destY) {
    queue<pair<int, int>> q;
    q.push({x,y});
    vis[x][y] =1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int i=0; i<8; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx<0 || ny<0 || nx>=b || ny>= b)continue;
            if(vis[nx][ny]) continue;
            if(nx ==destX && ny ==destY) {
                return vis[cur.X][cur.Y] +1;
                break;
            }
            q.push({nx,ny});
            vis[nx][ny] = vis[cur.X][cur.Y] +1;
        }
    }
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int b;
        cin >> b;
        int x, y;
        cin >> x >> y;
        int destX, destY;
        cin >> destX >> destY;

        if(x ==destX && y == destY) {
            cout << 0<<"\n";
            continue;
        }

        cout << bfs(x, y,b, destX, destY) -1<< "\n";

        //vis 배열 초기화시켜주깅
        for(int i=0; i< b; i++) {
            fill(vis[i], vis[i]+b,0);
        }
    }


}
