#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define X first
#define Y second
bool cmp(const pair<int, string> &a, const pair<int,string> & b) {
    return a.X < b.X;
}

//중복 단어 제거해야됨
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >> tc;

    vector<pair<int, string>> store;
    while(tc--) {
        int age; cin >>age;
        string name; cin >>name;

        store.push_back({age,name});
    }

    stable_sort(store.begin(), store.end(), cmp);

    for(auto cur: store)cout << cur.X << " "<< cur.Y << '\n';
}
