import java.util.*;
import java.io.*;

/*
[문제]
기능은 진도가 100일때 배포 가능
각 기능의 개발속도는 모두 다르다.
profresses - 먼저 배포되어야하는 순서대로 작업의 진도가 적힌 정수배열
speeds 각 작업의 개발속도

[입력]
배열의 길이는 100개 이하
진도는 100 미만의 자연수
작업 속도는 100'이하'의 자연수 - 한 번에 작업완료 가능
배포는 하루에 한 번만 할 수 있다

[IDEA]
stack사용

1. 배포 일자가 담긴 배열A 만들기
    -max = A[0]
3. A배열 2번부터 순회하면서 stack에 값 넣기
    - if(max < A[x])
        max = A[x];
        stack 사이즈 결과에 넣기
        stack비우기
        stack.push(A[x])수행
    -if (max>=A[x]) stack에 push

*/

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> A = new ArrayList<>();
        
        //일자 배열 만들기
        for(int i=0; i<progresses.length; i++){
            int count =0;
            while(progresses[i]<100){
                progresses[i] = progresses[i]+speeds[i];
                count++;
            }
            A.add(count);
        }
      
        Stack<Integer> stack = new Stack<>();
        int max=0;
        
        for(int i=0; i<A.size(); i++){
            if(stack.empty()){
                stack.push(A.get(i));
                max = A.get(i);
                
            }else if(max <A.get(i)){
                
                answer.add(stack.size());
                while(!stack.empty())stack.pop();
                stack.push(A.get(i));
                max = A.get(i);
                
            }else {
                stack.push(A.get(i));
            }
            
        }
        //모두 동시에 배포되는 경우 
        //날짜 배열이 모두 같은 경우이다.
        int size = stack.size();
        Boolean flag = true;
        
        int x=stack.peek();
        for(int i=0; i<size; i++){
            if(x!=stack.peek())flag = false;
            stack.pop();
        }
        
        if(!flag)answer.add(size);
        else answer.add(1);

        return answer;
    }
}