#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> store;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        store.push_back(x);
    }

    int answer = 0;
    for (int i = store.size()-1; i >= 0; i--) {
        if (k/store[i] >=1) {
            answer += k/store[i];
            k = k%store[i];
            if(k==0) break;
        }
    }

    cout << answer;

    return 0;
}
