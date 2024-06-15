#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
/*
 *N 이 입력 2<= N <= 100
 *size N*N
 *높이의 정보
 *
 *[필요한 것]
 *board[][] 원본 그래프 내용
 *min max 가낭 낮은 구역/ 가장 높은 구역
 *flood[][] 잠기는 그래프 내용
 *bfs 동서남북 배열 dx,dy
*vector partition 잠기는 구역들 표시

*/

int board[101][101];
int flood[101][101];

int dx[] ={-1,1,0,0};
int dy[] = {0,0,-1,1};




int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int min = 1000;
    int max = -1;
    vector<int> partition;
    //n*n받기
    int n; cin >>n;
    for(int height=0; height<n; height++) {
        for(int width =0; width<n; width++) {
            int x; cin >> x;
            board[height][width]=x;
            //min max 구하기
            if(min > x) min = x;
            if(max < x) max =x;
        }
    }

    for(int rain= 0; rain <=max; rain++) {
        //flood 초기화
        for(int i=0; i<n; i++) {
            fill(flood[i], flood[i] +n, 0);
        }
        //flood 생성
        for(int height=0; height < n; height++) {
            for(int width =0; width <n; width++) {
                if(board[height][width] <=rain ) {
                    flood[height][width] =1;
                }
            }
        }

        //bfs를 수행하고 카운트한 구역의 수
        int count=0;
        //bfs 수행 flood가지고 bfs 수행 bfs는 구역의 값을 return
        for(int height=0; height <n; height++) {
            for(int width =0; width<n; width++) {
                if(flood[height][width] ==0) {
                    //
                    // //for test
                    // cout << rain << " "<< count <<" =================== \n";
                    // for(int i=0 ;i<n; i++) {
                    //     for(int k=0; k<n; k++) {
                    //         cout << flood[i][k] << " ";
                    //     }
                    //     cout << "\n";
                    // }

                    count++;
                    //bfs수행
                    //초기화
                    queue<pair<int,int>> q;
                    q.push({height,width});
                    flood[height][width]=1;
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();

                        for(int dir=0; dir<4; dir++) {
                            int nx = cur.first+ dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx<0 || ny<0 || nx >= n || ny >= n)continue;
                            if(flood[nx][ny] ==1)continue;

                            q.push({nx,ny});
                            flood[nx][ny] =1;
                        }
                    }
                    partition.push_back(count);
                }
            }
        }

    }

    sort(partition.begin(),partition.end());

    cout<< partition[partition.size()-1];
}