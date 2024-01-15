import java.util.*;

class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
    
        long i =1;
        while(i<= n){
            answer[(int)i-1] = x*i;
            i++;
        }
        
        
        return answer;
    }
}