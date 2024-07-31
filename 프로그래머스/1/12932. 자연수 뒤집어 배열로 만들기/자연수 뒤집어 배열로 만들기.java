class Solution {
    public int[] solution(long n) {
        int[] answer = new int[Long.toString(n).length()];
        
        int idx=0;
        while(true){
            answer[idx] = (int)(n%10);
            n = n/10;
            if(n==0)break;
            idx ++;
            
        }
        
        
        
        return answer;
    }
}