#include <iostream>
#include <algorithm>;
#include <queue>;
#include <cstdlib>
#include <vector>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >>tc;

    string answer="";
    while(tc--) {
        int w,h; cin >> w>>h;
        char board[h][w];
        int fire[h][w];
        int hu[h][w];

        for(int i=0; i< h; i++) {
            fill(fire[i], fire[i] +w ,0);
            fill(hu[i], hu[i] +w, 0);
        }
        queue<pair<int,int>> fq;
        queue<pair<int,int>> hq;

        for(int i=0; i< h; i++) {
            cin >> board[i];
            for(int k=0; k<w; k++) {
                if(board[i][k] == '@') {
                    hu[i][k] =1;
                    hq.push({i,k});
                }
                if(board[i][k]== '*') {
                    fire[i][k]=1;
                    fq.push({i,k});
                }
            }
        }

        //fire bfs
        while(!fq.empty()) {
            auto cur = fq.front(); fq.pop();

            for(int i=0; i<4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx<0 || ny<0 || nx>=h || ny>=w)continue;
                if(board[nx][ny] =='#' || fire[nx][ny] !=0)continue;
                fq.push({nx,ny});
                fire[nx][ny] = fire[cur.first][cur.second]+1;
            }
        }

        bool flag = false;
        while(!hq.empty() && (!flag)) {
            auto cur = hq.front(); hq.pop();

            for(int i=0; i<4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx<0 || ny<0 || nx>=h || ny >=w){
                    cout << hu[cur.first][cur.second]<< "\n";
                    flag = true;
                    break;
                }

                if(board[nx][ny] =='#' || hu[nx][ny] !=0)continue;
                if(fire[nx][ny] <= hu[cur.first][cur.second]+1 && fire[nx][ny] !=0 )continue;

                hq.push({nx,ny});
                hu[nx][ny] = hu[cur.first][cur.second]+1;
            }
        }

        // for(int i=0; i<h; i++) {
        //     for(int k=0; k<w; k++) {
        //         cout<< fire[i][k]<< " ";
        //     }
        //     cout << "\n";
        // }
        //
        // cout << "=====\n";
        // for(int i=0; i<h; i++) {
        //     for(int k=0; k<w; k++) {
        //         cout<< hu[i][k]<< " ";
        //     }
        //     cout << "\n";
        // }

        if(flag==false)cout << "IMPOSSIBLE \n";

    }
    cout << answer;
}
