import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = s.length();
        
        int count=1;
        for(int i=1; i<=s.length()/2; i++){
            
            StringBuilder result = new StringBuilder();
            
            String start = s.substring(0,i);
            
            for(int k=i; k<=s.length(); k= k+i){
                int end = Math.min(k+i, s.length());
                
                String compare = s.substring(k, end);
                
                if(start.equals(compare)){
                    count++;
                }else{
                    if(count>=2)result.append(count);
                    result.append(start);
                    start = compare;
                    count=1;
                }
            }
            result.append(start);
            answer = Math.min(answer,result.length());
            
        }
        return answer;
    }
}