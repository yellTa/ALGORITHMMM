#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
bool cmp(const int &a, const int &b) {
    return a>b;
}
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int tc; cin >>tc;

    while(tc--) {
        int n,m; cin >>n >>m;

        vector<int> A(n);
        vector<int> B(m);

        for(int i=0 ;i<n; i++) cin >>A[i];
        for(int i=0; i<m; i++) cin>> B[i];

        sort(A.begin(), A.end(),cmp);

        sort(B.begin(), B.end(),cmp);

        int answer=0;
        for(int i=0; i< n; i++) { //A먼저 순회하기
            for(int k=0; k<m; k++) { // B순회하기
                if(A[i]>B[k]) {
                    answer += B.size()-k;
                    break;
                }
            }
        }
        cout << answer<<"\n";
    }
}
