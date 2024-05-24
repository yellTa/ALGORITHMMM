#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>//less
/*
loswer scoville + second lowest scoville*2

mix it until uppter than k
[enter]
2<=scoville.size()<=10^6
0<=scoville<=10^6
0<=k <10^9

[output]
mix count

If not possible upper than K then return -1

[IDEA]
1,2mix and result = 3,'5',9,10,12 
the 5 is new value 
-> put the value in the DataStructure
-> and sorting again -> use proirity queue ,min heap
*/
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //descending setup
    priority_queue<int, vector<int>, greater<int>>queue;
    
    for(int x : scoville)queue.push(x);
    
    while(queue.size() >=2){
        int x1 = queue.top(); queue.pop();
        if(x1>=K)return answer;
        int x2 = queue.top(); queue.pop();
        int mixed = x1 + (x2*2);
        answer ++;    
        queue.push(mixed);
        
    }
    if(queue.top()>=K)return answer;
    else return -1;
}