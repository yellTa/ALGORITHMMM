#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int value[30];
int cnt = 0;

void func(int cur, int sum) {
    if(cur ==n) {
        if(sum == s)cnt++;
        return;
    }
    func(cur+1, sum); //자기자신인 경우
    func(cur+1, sum+value[cur]);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    func(0, 0);

    if (s == 0) cnt--; // 공집합 제외
    //아무것도 선택 안해서 0이 되는 경우
    cout << cnt;

    return 0;
}
