#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    stack<int> stack;
        
        for(int i=numbers.size()-1; i>=0; i--){
           while(!stack.empty() && numbers[i] >= stack.top()){
               stack.pop();
           }
            
            if(!stack.empty()){
                answer[i] = stack.top();
            }
            
            stack.push(numbers[i]);
        }
    return answer;
}