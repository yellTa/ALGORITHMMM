import java.util.*;

class Solution {
    public long[] solution(int n, long left, long right) {
        long[] answer = new long[(int)(right-left+1)];
        
        // key -value 쌍 만들기
        Map<Integer, Integer> map = new HashMap<>();
        
        //숫자 채우기
        int idx=0;
        for(long i=left;i<right+1;i++){
            answer[idx] =(long)( Math.max(i/n, i%n)+1);
            idx++;
        }
        
        return answer;
    }
}