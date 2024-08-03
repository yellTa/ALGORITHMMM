import java.util.*;
class Solution {

    
    public long solution(int n, int[] times) {
        
        Arrays.sort(times);
        long st =1;
        long en = (long) n * times[times.length - 1]; 
        
        long answer=en;
        
        while(st<=en){
            long mid = (st+en)/2;
            
            long people =0;
            for(int i=0; i< times.length; i++){
                people += mid/times[i];
            }
            
             if (people < n) {
                st = mid + 1;
            } else {
                answer = mid; // 가능한 최소 시간
                en = mid - 1;
            }
        }
        
        return answer;
    }
}