import java.util.*;
import java.io.*;
/*
중복제거
문제
set에 넣어서 제거해버리자
*/

public class Solution {
    public List<Integer> solution(int []arr) {
        List<Integer> answer = new ArrayList<>();
        
        Stack<Integer> stack = new Stack<>();
        for(int x : arr){
            if(!stack.empty() && stack.peek()==x)continue;
            stack.push(x);
        }
        
        for(int z : stack){
            answer.add(z);
        }
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

        return answer;
    }
}