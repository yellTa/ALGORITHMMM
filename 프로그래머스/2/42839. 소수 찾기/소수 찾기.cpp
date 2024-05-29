#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

bool isPrime(int n){
    if(n<2)
        return false;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i ==0 )return false;
    }
    
    return true;
}

int solution(string numbers) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int answer = 0;
    
    set<int> ans{};
    sort(numbers.begin(), numbers.end());
    
    do{
        string tmp;
        for(int i=0; i<numbers.size(); ++i){
            tmp +=numbers[i];
            if(isPrime(stoi(tmp)))
                ans.insert(stoi(tmp));
            
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
        answer = ans.size();
    return answer;
}