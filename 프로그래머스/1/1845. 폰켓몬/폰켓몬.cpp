#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    set<int> set;
    
    
    for(int i: nums){
        set.insert(i);
    }
    int m =set.size();
    int k= nums.size()/2;
    
    if(m<k){
        return m;
    }else{
        return k;
    }

}