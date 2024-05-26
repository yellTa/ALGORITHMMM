#include <iostream>
#include <vector>
#include <algorithm>

/*
[Question]
make biggest number which combination of numbers

[Enters]
1<=numers<=10^6
0<=numbers[i] <=10^3;

-> 0이 여러번 들어올 수 있는 가능성 존재

[IDEA]
String order-> 1, 10 ,20 ,22 ,23, 30...


String을 활용한 정렬방식 적용
ex string a =1
string b = 10
 a+b = 110
 b+a = 101
 
 a+b > b+a 큼- > return a+b > b+a
 반대로 작게 return 하려면 b+a> a+b return


logic time : 5mins
*/
using namespace std;
//compare func
bool cmp (string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> sv;
    for(int x : numbers){
        sv.push_back(to_string(x));
    }
    sort(sv.begin(), sv.end(),cmp);
    
    for(string s : sv) answer += s;
    if(sv[0] =="0") return "0";
    return answer;
}