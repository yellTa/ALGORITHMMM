#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n; cin >>n;

    pair<int,int> p[41];
    p[0]  = {1,0};
    p[1] = {0,1};

    for(int i=2;i<=40; i++) {
        int x = p[i-2].first +p[i-1].first;
        int y = p[i-2].second + p[i-1].second;

        p[i] = {x,y};
    }

    while(n--) {
        int x; cin>>x;
        cout << p[x].first << " "<<p[x].second<<"\n";
    }

}