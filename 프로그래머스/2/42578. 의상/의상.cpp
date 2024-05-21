#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
[문제]
코니가 어제 입은옷 종류 ABCD
다음날에는  ABCD'E'추가하거나 AB'F'D 변경이 되어야 함

[입력]
의상의 이름, 의상 종류
1<= 의상 수 <=30
같은 이름을 가진 의상 없음
원소는 문자열
1<= 문자열의 길이<=20
알파벳 소문자 or _


[문제의 조건]
1.각 종류별로 최대 1가지만 착용 가능 (선글라스 두개 착용 불가)
2.추가로 착용한 경우에는 통과
3.입은 의상 수가 같고 다른게 변경된 경우
4.최소 한개는 입는다. -> 한 개인 경우도 존재한다.

[IDEA]
모든 조합을 생각해야하는 문제

[[a,A],[b,B],[c,C]]의 형식 참고로 옷을 추가로 입는 경우도 존재한다.
[[a,A],[b,A],[c,A]]의 입력도 주어진다.
일떄 
A = a,b = 2
B = c,d,f =3
C = z =1
를 놓고 모든 경우의 수를 생각해야 한다.
모든 경우의 수는 간단하다.
map의 size값에 +1을 한후 곱해주면 된다.
a,b(a,b를 입는 경우) +1(벗어버리는 경우) =3
c,d,f(c,d,f를 입는경우) +1 (안입는 경우) =4
z(z를 입는 경위) +1(안입는 경우) = 2

3*4*2 = 24
총 경우의 수는 24가 나오나 여기 해당하는 경우는 세 가지를 모두 안입는 경우도 포함이다.
따라서 답은 -1을 해주면된다.

[수도코드]
1. 배열 받기
2. 받은 배열 for문 돌리기
   꺼낸 배열 A[1] key getOrDefault(key, 0)+1 해주기

3. map을 돌면서 value +1을 answer에 계속 곱해주기
4. answer-1리턴하기
*/

int solution(vector<vector<string>> clothes) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int answer=1;
    unordered_map<string,int> hashMap;
    
    for(int i=0; i< clothes.size(); i++){
        hashMap[clothes[i][1]]++;
    }
    
    for(auto n : hashMap){
        answer = answer *(n.second +1); // first,second
        //first(key) ,second(value)
    }
    
    
    return answer-1;
}