#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>


#define X first
#define Y second

using namespace std;

bool cmp (const pair<int, int> &a , const pair<int,int>& b) {
    return a.Y > b.Y;
}

//중복 단어 제거해야됨
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >>tc;
    int c; cin >>c;

    vector<pair<int,int>> store;

    for(int i=0; i< tc; i++){ // 수 받기
        int x; cin >>x;

        bool flag = false;
        //store에 들어있는 경우
        for(auto& cur : store) {
            if(cur.X == x) {
                flag = true;
                cur.Y++;

            }
            if(flag) break;
        }
        //처음 등장한 숫자인 경우
        if(!flag) store.push_back({x,1});
    }

    stable_sort(store.begin(),store.end(),cmp);

    for(auto cur : store) {
        for(int i=0; i< cur.Y; i++)cout << cur.X << " ";
    }

}
