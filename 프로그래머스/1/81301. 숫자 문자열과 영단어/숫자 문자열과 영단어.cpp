#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long solution(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    string ans="";

    map<string, string> map;
    
    map.insert({"zero","0"});
    map.insert({"one","1"});
    map.insert({"two","2"});
    map.insert({"three","3"});
    map.insert({"four","4"});
    map.insert({"five","5"});
    map.insert({"six","6"});
    map.insert({"seven","7"});
    map.insert({"eight","8"});
    map.insert({"nine","9"});
    
    string str = "";
    
    for(char x : s){
        if(x>=48 && x<= 57){
            //map에 있는 value 꺼내기
            ans += x;
        }else{
            str+=x;
        }
        
        if(map.find(str) !=map.end()){
            ans+= map[str];
            str="";
        }
    }
    
    // cout << ans;
    return stol(ans);
}