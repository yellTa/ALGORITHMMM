import java.util.*;
import java.io.*;

/*
스택으로 풀어도 되지만 어짜피 주어지는 괄호의 쌍이 한 개만 존재해서 수리로 풀음
( =1
) = -1

닫힌 괄호가 시작으로 들어오면 이건 올바른 괄호가 될 수 없음

0일때 -1들어오면 false
마지막 수행 값이 0이 아니면 false

*/


class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        String A[] = s.split("");
        
        int result =0;
        
        for(String x : A){
            if(x.equals("(") ){
             result +=1;
             continue;
            }
            
            if(x.equals(")")){
                if(result==0){
                    return false;
                }
            }
            result -=1;
        }
        
        if(result==0)return true;
        else return false;
        
    }
}