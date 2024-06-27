#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    // priority_queue<int, vector<int>, greater<int>> pq;
    int t; cin >>t;
    priority_queue<int> pq;

    while(t--) {
        int x; cin >>x;
        pq.push(x);
    }

    while(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }

}
