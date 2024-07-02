#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define X first
#define Y second

bool cmp(const tuple<string, int,int,int>& a, const tuple<string ,int,int,int> & b) {
    //국어 점수가 다를 때 국어가 감소하는 순서 - 큰거에서 작은거로
    if(get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);

    // 국어 같으면 영어 점수가 증가 낮은데서 높은 값
    if(get<2>(a) !=get<2>(b))
        return get<2>(a) < get<2>(b);

    //국어랑 영어랑 같으면 수학 점수 감소(큰거에서 작은거로 내려감)
    if(get<3>(a)!=get<3>(b))
        return get<3>(a) > get<3>(b);

    //다 같으면 이름이 사전순
    return get<0>(a) < get<0>(b);


}


int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin>> tc;

    vector<tuple<string, int,int,int>> score;

    while(tc--) {
        string name; cin >> name;
        int ko, en, math; cin >> ko >>en >> math;

        score.push_back({name ,ko, en, math,});
    }

    sort(score.begin(), score.end(),cmp);

    for(auto cur : score) {
        // cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << " " << get<3>(cur)<<"\n" ;
        cout << get<0>(cur)<<"\n";
    }
}
