#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
/*
 * LRC 층/행/열
 * 3차원[L][R][C] h, y, x;
 *
 * 끝날 때 000으로 끝남
 *
 *[필요한 것]
 * 상하좌우위아래 검사 행렬
 * 3차원 정보 LRC
 * 3차원 map -> 시작점 끝점 그리고 맵 표시
 * 3차원 vis - > 방문한 곳 표시
 *
 * vector answers정답 배열
 *
*/
int dx[] ={-1,1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dh[] = {0,0,0,0,1,-1};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    vector<int> answers;
    while(true) {
        int L,R,C; cin >> L>> R>>C;
        if(L ==0 && R ==0 && C==0)break;

        //map 만들기
        char board[31][31][31];
        int vis[31][31][31];

        //초기화 하기
        for(int i=0; i<31; i++) {
            for(int k=0 ;k<31; k++) {
                fill(board[i][k], board[i][k] + 31,0);
                fill(vis[i][k], vis[i][k] + 31,0);

            }
        }

        
        queue<tuple<int,int,int>> q;
        for(int height = 0; height<L; height++) {
            for(int y = 0; y<R; y++) {
                string s; cin >>s;
                for(int x =0; x<C; x++) {
                    board[height][y][x] = s[x];
                    if(s[x] =='S') {
                        vis[height][y][x] = 1;
                        q.push({height,y,x});
                    }
                }
            }
        }


        bool flag=false;
        int count =0;
        //bfs 수행하기
        while(!q.empty()) {
            int h,y,x;
            tie(h,y,x) = q.front(); q.pop();

            for(int dir=0; dir<6; dir++) {
                int nh = h + dh[dir];
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(nx<0 || nx >=C || ny <0 || ny>=R || nh<0 || nh>=L)continue;
                if(board[nh][ny][nx] == '#' || vis[nh][ny][nx] !=0)continue;
                if(board[nh][ny][nx] =='E' && vis[nh][ny][nx] ==0) {
                    count = vis[h][y][x];
                    flag= true;
                    break;
                }

                vis[nh][ny][nx] = vis[h][y][x] +1;
                q.push(make_tuple(nh,ny,nx));
            }
            if(flag == true)break;

        }
        if(flag == true) {
            answers.push_back(count);
        }else answers.push_back(0);
        // //for check
        // for(int h=0; h<L; h++) {
        //     for(int y=0; y<R; y++) {
        //         for(int x=0; x<C; x++) {
        //             cout << board[h][y][x]<< " ";
        //         }
        //         cout << "\n";
        //     }
        //     cout << "\n";
        // }

        //for check end
    }

    for(int nxt : answers) {
        if(nxt ==0)cout<< "Trapped!\n";
        else cout << "Escaped in "<<nxt <<" minute(s). \n";
    }

}