#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int MA = 0;
int tempA = 0;
int answer = 0;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int m; cin >>m;

    queue<int>q;
    for(int i=1; i<=m; i++) {
        q.push(i);
    }

    while(q.size() !=1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}
