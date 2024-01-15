import java.util.*;

class Solution {
    public Long solution(long n) {
        ArrayList<String> answer = new ArrayList<>();
        String[] s = String.valueOf(n).split("");
        
        for(String j : s){
            answer.add(j);
        }
        Collections.sort(answer, Collections.reverseOrder());
        
        String r="";
        for(String a: answer){
        r += a ;   
        }
        
        return Long.parseLong(r);
    }
}