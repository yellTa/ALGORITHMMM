#include <stack>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[]= {1, -1, 0 ,0};
int dy[] = {0,0,-1,1};


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    int m,n; cin >>m>>n;

    int tomato[n][m]={};

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            string s;cin >>s;
            tomato[i][k] = stoi(s);
            if(s == "1")q.push({i,k});
        }
    }

    while(!q.empty()) {
        pair<int,int> temp = q.front();
        int cnt = tomato[temp.first][temp.second];
        q.pop();

        for(int i=0; i<4; i++) {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];

            if( x<0 || y<0 ||x >=n || y>=m )continue;
            if(tomato[x][y] == -1) continue;
            if(tomato[x][y] !=0) continue;
            tomato[x][y] = cnt+1;
            q.push({x,y});
        }

    }

    int max=0;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            if(tomato[i][k] ==0) {
                cout << -1;
                return 0;
            }
            if(tomato[i][k] > max) max = tomato[i][k];
        }

    }
    cout << max -1;
}

