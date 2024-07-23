#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int getGCD(vector<int>arr){
    int num1= arr[0];
    for(int i=1; i<arr.size(); i++){
        int num2 = arr[i];
        while(true){
            int num3 = num2 % num1;
            if(num3 ==0)break;
            
            num2 = num1;
            num1= num3;
        }
    }
    return num1;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    // ArrayA의 최대 공약수 구하기
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int aNum = getGCD(arrayA);
    int bNum= getGCD(arrayB);
    
    answer = max(aNum, bNum);
    
    if(answer == aNum){
        for(int x : arrayB){
            if(x%answer ==0) return 0;
        }
    }else {
        for(int x : arrayA){
            if(x%answer ==0 )return 0;
        }
    }
    

    return answer;
}