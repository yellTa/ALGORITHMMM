    #include <iostream>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

int main(void){
	 std::ios::sync_with_stdio(0);
	 std::cin.tie(0);
	 
	int tc; cin >>tc;
	
	while(tc--){
		int num,index; cin>>num>>index;
	
		queue<int> docs;
		queue<int> B;
		priority_queue<int> sorted;
		
		for(int i=0; i< num; i++){
			int temp;cin>>temp;
			docs.push(temp);
			sorted.push(temp);
			
			if(i ==index)B.push(1);
			else B.push(0);
			}
			
			int cnt=0;
			
			while(1){
				if(docs.front() != sorted.top()){
					int x = docs.front();
					docs.pop();
					docs.push(x);
					
					int y = B.front();
					B.pop();
					B.push(y);
				}
				
				if(docs.front() == sorted.top()){
					cnt++;
					if(B.front() == 1){
						break;
						}
					
					docs.pop();
					B.pop();
					sorted.pop();
					}
				
				
				}
			
				cout << cnt<<"\n";
				
	}
	
				
}
