import java.util.*;
import java.io.*;

/*
[문제]
수를 만드는 경우의 수를 모두 구하기
숫자는 순서를 바꾸지 않고 연산을 수행한다.

[입력]
2<=숫자의 갯수<=20
1<=숫자<=50
1<=타겟 숫자<=1000

[IDEA]
+- -> 0(+),1(-)로 구성된 모든 경우의 수 board 생성
board의 행을 따라서 연산 수행
수행한 값이 target과 같으면 count한다.

근데 board생성하는 방법을 모르겠으니까 답지 보기

이번엔 dfs 문제이다.

[pseudo]
1.board생성(0,1 (+,-))

2. 연산 수행로직

3. 값 return

*/


class Solution {
    
   int answer = 0;
   
    public int solution(int[] numbers, int target) {

        dfs(numbers,0, target, 0);
        
        return answer;
    }
    
     public void dfs(int[] numbers, int depth, int target,int sum){
        if(depth == numbers.length){
            if(target ==sum)answer++;
        }else{
            dfs(numbers,depth+1, target, sum+numbers[depth]);
            dfs(numbers, depth +1, target, sum - numbers[depth]);
        }
    }
    
}