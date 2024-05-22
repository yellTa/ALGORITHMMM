#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/*
stack에 데이터를 넣기
stack의 top이 집어넣으려는 값이랑 같으면 continue;
*/
vector<int> solution(vector<int> arr) 
{
    
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    vector<int> answer;

    stack<int> stack;
    for(int x : arr){
        if(!stack.empty() && stack.top() == x)continue;
        stack.push(x);
       answer.push_back(x);
    }
    

    return answer;
}