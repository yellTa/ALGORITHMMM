#include <stack>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int maze[101][101];
int vis[101][101];
int dx[]= {1, -1, 0 ,0};
int dy[] = {0,0,-1,1};


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m; cin >>n>>m;

    for(int i=1; i<=n; i++){
        string s; cin >> s;
        for(int k=1; k<=m; k++) {
             maze[i][k]= s[k-1]-'0';
        }
    }

    queue<pair<int, int>> q;
    q.push({1,1});
    vis[1][1] = 1;

    int cnt=1;
    while(!q.empty()) {
        pair<int,int> temp = q.front();
        q.pop();
        // cout << temp.first<< ","<< temp.second<< ": "<< vis[temp.first][temp.second]<<"\n";
        cnt = vis[temp.first][temp.second];
        for(int i=0; i< 4; i++) {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];

            if(x<1 || y<1 || x>n || y>m) continue;
            if(vis[x][y] || maze[x][y]==0)continue;
                vis[x][y] =cnt+1;
                q.push({x,y});

        }
    }
    cout << vis[n][m];

}

