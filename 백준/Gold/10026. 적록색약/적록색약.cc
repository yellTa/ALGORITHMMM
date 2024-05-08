#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

char board[101][101];
int vis1[101][101];
int vis2[101][101];


int dx[] = {-1, 1, 0 ,0};
int dy[] = {0,0,-1,1};
int n;
int m;

void bfs1(int i, int k) {
    queue<pair<int,int>> q;
    q.push({i,k});
    vis1[i][k] =1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int j=0; j<4; j++) {
            int x = cur.X+ dx[j];
            int y = cur.Y +dy[j];

            if(x<0 || y<0 || x>=n || y>=m)continue;
            if(vis1[x][y] || board[x][y] != board[cur.X][cur.Y]) continue;

            q.push({x,y});
            vis1[x][y] =1;
        }
    }

}
void bfs2(int i, int k) {
    queue<pair<int,int>> q;
    q.push({i,k});
    vis2[i][k] =1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for(int j=0; j<4; j++) {
            int x = cur.X+ dx[j];
            int y = cur.Y +dy[j];

            if(x<0 || y<0 || x>=n || y>=m)continue;
            if(vis2[x][y]) continue;
            //적록색약이면 빨강 초록을 같은 취급...
            //기준점이 B일때
            if(board[cur.X][cur.Y] =='B' && board[x][y] !='B') continue;
            //기준짐이 R아니고 R or G일떄
            if(board[cur.X][cur.Y] !='B' && board[x][y] =='B') continue;
            q.push({x,y});
            vis2[x][y] =1;
        }
    }

}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >>n; //세로줄 받기

    for(int i=0; i<n; i++) {
        string s ; cin >> s;
        m = s.size();
        for(int k=0; k<s.size();k++ ) {
            board[i][k] = s[k];
        }
    }

    int cnt1 =0;
    int cnt2 =0;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m;k++ ) {
            if(vis1[i][k] ==0){ // 멀쩡눈알 bfs
                cnt1 +=1;
                bfs1(i,k);

            }
            if(vis2[i][k] ==0) {//재준눈알 bfs
                cnt2 +=1;
                bfs2(i,k);
            }

        }

    }




    cout << cnt1 << " " <<cnt2;

    return 0;
}
