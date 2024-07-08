#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int vis[301][301];
int mountain[301][301];
int temp[301][301];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void melt(int n, int m) {
    for (int i = 0; i < n; i++) fill(temp[i], temp[i] + m, 0);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (mountain[i][k] > 0) {
                int ice = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = k + dy[dir];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && mountain[nx][ny] == 0) ice++;
                }
                temp[i][k] = max(0, mountain[i][k] - ice);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) mountain[i][k] = temp[i][k];
    }
}

void bfs(int x, int y, int n, int m) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mountain[nx][ny] > 0 && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

bool isSeparated(int n, int m) {
    fill(&vis[0][0], &vis[0][0] + 301 * 301, 0);
    int chunks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mountain[i][j] > 0 && !vis[i][j]) {
                if (chunks > 0) return true;
                bfs(i, j, n, m);
                chunks++;
            }
        }
    }
    return false;
}

bool hasIce(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mountain[i][j] > 0) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> mountain[i][k];
        }
    }

    int years = 0;

    while (true) {
        melt(n, m);
        years++;
        if (isSeparated(n, m)) {
            cout << years << endl;
            return 0;
        }
        if (!hasIce(n, m)) {
            cout << 0 << endl;
            return 0;
        }
    }
}
