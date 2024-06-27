#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int cmp(tuple<int, string, int>& a,tuple<int, string, int>& b) {
    if (get<0>(a) == get<0>(b)) {
        return get<2>(a) < get<2>(b); // 나이가 같으면 인덱스 순으로
    }
    return get<0>(a) < get<0>(b); // 나이 순으로
}
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    // priority_queue<int, vector<int>, greater<int>> pq;
    int t; cin >>t;

    vector<tuple<int, string, int>> users; // age, name, index
    for(int i=0 ; i<t; i++) {
        int age; cin>> age;
        string name; cin >> name;

        users.push_back({age,name,i});
    }
    sort(users.begin(), users.end(),cmp);
    for (const auto& user : users) {
        cout << get<0>(user) << " " << get<1>(user) << "\n";
    }
}
