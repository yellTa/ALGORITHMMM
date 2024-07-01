#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
long long turn(string x) {
   string freshInt;

    for(int i= x.size()-1; i>=0; i--) {
        freshInt +=x[i];
    }

    return stoll(freshInt);
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >>tc;
    vector<long long> store;
    while(tc--) {
        string x ; cin >>x;
        //뒤집기
        long long freshInt = turn(x);
        // cout << freshInt<<"\n";
        //넣기
        store.push_back(freshInt);
    }
    //정렬하기
    sort(store.begin(), store.end());

    for(auto x : store) {
        cout << x << "\n";
    }
}
