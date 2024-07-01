#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
    if(a.length() == b.length()) return a<b;
    return a.length() < b.length();
}

//중복 단어 제거해야됨
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >>tc;

    set<string> store;
    while(tc--) {
        string s; cin >>s;
        store.insert(s);
    }
    //set to vector

    vector<string> v(store.begin(), store.end());
    sort(v.begin(), v.end(), cmp);
    for(auto word : v) cout << word << "\n";
}
