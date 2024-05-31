#include<vector>
#include<iostream>
#include <queue>

#define X first
#define Y second
using namespace std;
/*
[문제]
동서남북으로 이동
내 위치 (1,1)
상대방 위치(n,m)
0은 벽이있는자리 1은 벽이 없는자리- >1일때 지나갈 수 있다.

1<=n,m<=100

[IDEA]
bfs를 구해서 최단 거리를 구한다. n,m의 좌표 거리를 구한다.
visted배열 생성

동서남북 검사
벽일 경우 가지 않는다.
이미 지나간 곳이면 가지 않는다.(visited에 값이 있는 경우)
0이 벽임
1이 지나가는 곳임

*/

int board[102][102]={0};
int vis[102][102]={0};

int dx[] ={-1, 1, 0, 0};
int dy[] = {0,0, -1,1};

int solution(vector<vector<int> > maps)
{   std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    //가로, 세로
    int n = maps.size()-1;
    int m= maps[0].size()-1;
 
    for(int i=0; i< maps.size(); i++){
        for(int k=0; k< maps[i].size(); k++){
            board[i][k] = maps[i][k];
        }
    }
    
    queue<pair<int,int>> q;
    
    q.push({0,0});
    vis[0][0] =1;

    while(!q.empty()){
    auto cur = q.front(); q.pop();
    
    for(int i=0; i<4; i++){
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];

        if(nx <0 || ny <0 || nx>n || ny >m) continue;
        if(vis[nx][ny] !=0 || board[nx][ny]==0)continue;
        
        q.push({nx,ny});
        vis[nx][ny] = vis[cur.X][cur.Y]+1;
        }    
        
    }
 
    if(vis[n][m] == 0) return -1;
    else return vis[n][m];
 
}