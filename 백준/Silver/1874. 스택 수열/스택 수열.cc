#include <iostream>
#include <stack>


using namespace std;

int main(void){
	 std::ios::sync_with_stdio(0);
	 std::cin.tie(0);
	 
	 int tc; cin >>tc;
	 
	 string answer="";
	 
	 int idx=1;
	 stack<int> stack;
	 
	 for(int i=0;i<tc;i++){
	 	int n; cin >>n;
	 		while(idx <=n){
	 			stack.push(idx++);
	 			answer += "+ \n";
	 			}
	 			
	 		if(stack.top() >n){
	 		answer = "NO";
	 			break;
	 			
	 			}
	 		stack.pop();
	 		answer +="- \n"; 
		}
		cout<< answer;	
	}
