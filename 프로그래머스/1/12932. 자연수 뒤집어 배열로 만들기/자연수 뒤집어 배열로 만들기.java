import java.util.*;

class Solution {
    public ArrayList<Integer> solution(long n) {
        ArrayList<Integer> answer  = new ArrayList<>();
        String[] s = String.valueOf(n).split("");
        
        for(int i=s.length; i>=1; i--){
            answer.add(Integer.parseInt(s[i-1]));
        }
            
        
        return answer;
    }
}