#include <vector>
#include <iostream>
#include <set>
using namespace std;
/*
set에 데이터 저장하기 

n/2 >set.size() n/2출력하기

n/2 <= set.size() set.size() 출력하기


*/
int solution(vector<int> nums)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int answer = 0;
    set<int> s;
    for(int x: nums){
        s.insert(x);
    }
    
    cout <<s.size();
    
    if(nums.size()/2 > s.size()){
        answer = s.size();
    }else answer = nums.size()/2;
    
    
    return answer;
}