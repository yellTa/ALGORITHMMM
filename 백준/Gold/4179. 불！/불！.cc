#include <queue>
#include <cmath>
#include <iostream>

#define X first
#define Y second

using namespace std;

int fire[1001][1001];
int jihun[1001][1001];

int dx[4] = {-1, 1 ,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> FQ;
queue<pair<int,int>> JQ;
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m; cin >>n >>m;

    for(int i=0; i<n; i++) {
        string s; cin>>s;
        for(int k=0; k<m; k++) {
            if(s[k] == '#') {
                fire[i][k] = -1;
                jihun[i][k] = -1;

            }
            if(s[k] == 'F') {
                fire[i][k] = 1;
                FQ.push({i,k});
            }
            if(s[k] == 'J') {
                jihun[i][k] = 1;
                JQ.push({i,k});
            }

        }
    }

    //fire bfs start
    while(!FQ.empty()) {
        auto cur = FQ.front(); FQ.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx<0 || nx>=n || ny <0 || ny>=m)continue;
            if(fire[nx][ny] || fire[nx][ny] == -1)continue;

            FQ.push({nx,ny});
            fire[nx][ny] = fire[cur.X][cur.Y] +1;
        }
    }

    //jihun bfs start
    while(!JQ.empty()) {
        auto cur = JQ.front(); JQ.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx<0 || nx>=n || ny <0 || ny>=m) {
                cout << jihun[cur.X][cur.Y];
                return 0;
            }
            if(jihun[nx][ny] == -1 || jihun[nx][ny] !=0)continue;
            if(jihun[cur.X][cur.Y] +1 >= fire[nx][ny] && fire[nx][ny] !=0) continue;
            
            
            JQ.push({nx,ny});
            jihun[nx][ny] = jihun[cur.X][cur.Y] +1;
        }
    }


    cout << "IMPOSSIBLE";
}