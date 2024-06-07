#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n,m,k;

int board[101][101];
int vis[101][101];

int dx[4] = {0,0,-1,1};
int dy[4]={ -1 ,1, 0,0};

int bfs(queue<pair<int,int>> q) {
    int count =1;
    while(!q.empty()) {

        auto cur = q.front(); q.pop();

        for(int dir = 0; dir <4; dir++) {
            int nx  = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx <0 || nx>=n || ny <0 || ny >=m)continue;
            if(board[nx][ny] || vis[nx][ny])continue;

            q.push({nx,ny});
            count++;
            vis[nx][ny]=1;
        }

    }
    return count;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >> m >>n >>k;

    while(k--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2>> y2;

        for(int y = y1; y <y2; y++) {
            for(int x = x1; x< x2; x++) {
                board[x][y] =1;
            }
        }

    }


    //test code
    queue<pair<int,int>> q;
    vector<int> answer;
    int count =0;
    for(int i=0; i< n; i++) {
        for(int k=0; k< m; k++) {
            if(!board[i][k] && !vis[i][k]) {
                count ++;
                q.push({i,k});
                vis[i][k]=1;
                answer.push_back(bfs(q));
            }
        }

    }

    sort(answer.begin(), answer.end());

    cout << count<<"\n";
    for(int x: answer) cout << x << " ";



}
