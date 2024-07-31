#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin>>tc;

    priority_queue<int> pq;
    while(tc--) {
        int command; cin>> command;

        if(command ==0 ) {
            if(pq.empty())cout << 0<< "\n";
            else {
                int x = pq.top();
                pq.pop();
                cout << x<< "\n";
            }
        }else {
            pq.push(command);
        }
    }



    return 0;
}
