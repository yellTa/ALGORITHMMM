import java.util.*;


class Solution {
    public int solution(String t, String p) {
        int answer = 0;

            for(int i=0; i<10000; i++){
                if(i+p.length() > t.length()){
                    break;
                }else{
                   long a = Long.parseLong(t.substring(i,i+p.length()));
                    if(a<=Long.parseLong(p)){
                        answer++;
                    }
                }
                
            }
        
        
        return answer;
    }
}