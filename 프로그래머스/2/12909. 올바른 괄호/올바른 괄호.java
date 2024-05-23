import java.util.*;
import java.io.*;

/*
( =1
) = -1

0일때 -1들어오면 false

마지막 수행 값이 0이 아니면 false

*/


class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        String A[] = s.split("");
        int result =0;
        for(String x : A){
            if(x.equals("(") )result +=1;
            else if(x.equals(")")){
                if(result==0){
                    return false;
                }
                result -=1;
            }
        }
        if(result ==0)return true;
        else return false;
        
    }
}