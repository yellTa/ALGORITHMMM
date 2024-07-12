#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;
int n,m;
int vis[301][301];
int mountain[301][301];
int temp[301][301];
int portion;
int years;

int dx[4] = {-1 ,1, 0,0};
int dy[4] = {0,0,-1,1};

bool bfs() {
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            if(mountain[i][k] && !vis[i][k]) {
                queue<pair<int,int>> q;
                q.push({i,k});
                vis[i][k] =1;

                while(!q.empty()) {
                    auto cur = q.front(); q.pop();

                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 경계 조건 추가
                        if(mountain[nx][ny] && !vis[nx][ny]) {
                            q.push({nx,ny});
                            vis[nx][ny] =1;
                        }

                    }
                }
                portion++;
                if(portion>=2) return true;
            }
        }
    }
    return false;
}
void melting() {
    for(int i=0 ; i<n; i++) {
        for(int k=0; k<m; k++) {
            if(mountain[i][k]) {
                //동서남북 체크하기
                int ice=0;
                for(int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = k + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 경계 조건 추가
                    if(vis[nx][ny]==0)ice++;
                }
                temp[i][k] = max(0, mountain[i][k]-ice);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++)mountain[i][k] = temp[i][k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >>m;

    bool flag=false;

    for(int i=0; i< n; i++) {
        for(int k=0 ;k<m; k++) {
            cin >> mountain[i][k];

            if(mountain[i][k]) {
                flag = true;
                vis[i][k]=1;
            }
        }
    }

    if(!flag) {
        cout << 0; return 0;
    }

    while(true) {
        melting();
        years++; //시간이 흘러서 녹아부림

        //bfs 수행을 위해서 vis 초기화 해주기

        fill(&vis[0][0], &vis[0][0] + 301 * 301, 0);  // vis 배열 초기화

        portion=0;

        if(bfs()) {
            cout << years;
            return 0;
        }

        // 모든 빙산이 다 녹았는지 확인
        bool allMelted = true;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (mountain[i][k] > 0) {
                    allMelted = false;
                    break;
                }
            }
            if (!allMelted) break;
        }

        if (allMelted) {
            cout << 0;
            return 0;
        }

    }

}
