#include <string>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    vector<int> answer;
    vector<int> A;
   for(int i=0; i<progresses.size(); i++){
       int count =0;
       while(progresses[i] <100){
           progresses[i] += speeds[i];
           count ++;
       }
       A.push_back(count);
   }
    
    stack<int> stack;
    int max=0;
    
    for(int i=0; i<A.size(); i++){
        if(stack.empty()){
            stack.push(A[i]);
            max = A[i];
        }else if(max < A[i]){
            answer.push_back(stack.size());
            while(!stack.empty())stack.pop();
            max = A[i];
            stack.push(A[i]);
            
        }else stack.push(A[i]);
    }
    
    int size =stack.size();
    bool flag = true;
    
    int x = stack.top();
    for(int i=0; i<size; i++){
        if(x!=stack.top()){
            flag = false; break;
        }
        stack.pop();
    }
    
    if(!flag)answer.push_back(size);
    else answer.push_back(1);
    
    return answer;
}