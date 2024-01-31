import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        ArrayList<Integer> str = new ArrayList<Integer>();
        
        for(String a : s.split("")){
            str.add((int)a.charAt(0));
        }
        
         Collections.sort(str, Collections.reverseOrder());
        
        for(int c: str){
            String b  = Character.toString((char)c);
            answer += b;
        }
        
        return answer;
    }
}