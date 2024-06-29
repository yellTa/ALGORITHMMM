#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;


bool cmp(const string& a, const string& b) {
    if(a.length() != b.length()) {
        return a.length()<b.length();
    }
    else if(a.length() == b.length()) {
        //a,b 자릿수 숫자 구하기
        //a먼저
        int anum=0,bnum=0;

        for(char charA: a)
            if(charA>=48 && charA<=57) anum +=(charA - '0');

        for(char charB : b)
            if(charB>=48 && charB<=57) bnum +=(charB - '0');

        if(anum!=bnum) return anum < bnum;
        return a<b;
    }

}
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc; cin >>tc;

    vector<string> store;
    while(tc--) {
        string s; cin >>s;
        store.push_back(s);
    }

    sort(store.begin(),store.end(),cmp);

    for(auto answer : store) cout << answer <<"\n";
}
