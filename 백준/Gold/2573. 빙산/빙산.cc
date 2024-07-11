#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define X first
#define Y second

using namespace std;

int n, m;
int years = 0;

int mountain[300][300];
int temp[300][300];
bool vis[300][300];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int i, int k) {
    queue<pair<int, int>> q;
    q.push({i, k});
    vis[i][k] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (mountain[nx][ny] > 0 && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

void melting() {
    memset(temp, 0, sizeof(temp)); // Initialize temp array with 0

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (mountain[i][k] > 0) {
                int ice = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = k + dy[dir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mountain[nx][ny] == 0) {
                        ice++;
                    }
                }
                temp[i][k] = max(0, mountain[i][k] - ice);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            mountain[i][k] = temp[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int, int>> meltStore;
    bool zeroMelt = false;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> mountain[i][k];
            if (mountain[i][k] > 0) {
                meltStore.push_back({i, k});
                zeroMelt = true;
            }
        }
    }

    if (!zeroMelt) {
        cout << 0;
        return 0;
    }

    while (true) {
        melting();
        years++;

        // 덩어리 구하기
        memset(vis, 0, sizeof(vis)); // Initialize vis array with 0
        int portion = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (mountain[i][k] > 0 && !vis[i][k]) {
                    bfs(i, k);
                    portion++;
                }
            }
        }

        if (portion >= 2) {
            cout << years;
            return 0;
        }

        if (portion == 0) {
            cout << 0;
            return 0;
        }
    }
}
