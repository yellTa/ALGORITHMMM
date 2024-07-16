#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>


#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int t;
        cin >> t;
        multiset<int> ms;

        while (t--) {
            char command;
            int n;
            cin >> command >> n;

            if(command=='D') {
                if(ms.empty()) continue;
                if(n==1)ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }else {
                ms.insert(n);
            }
        }

        if (ms.empty()) {
            cout << "EMPTY \n";
        } else {
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        }
    }
}
