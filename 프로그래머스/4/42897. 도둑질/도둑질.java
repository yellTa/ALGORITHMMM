class Solution {
    public int solution(int[] money) {
        int answer = 0;
        //첫 번째 집을 터는 경우
        int [] dp1 = new int[money.length];
        dp1[0] = money[0];
        dp1[1] = Math.max(money[0],money[1]);
        
        int max1=-1;
        //첫 집을 터는경우-> 마지막 집은 검사하지 않는다.
        for(int i=2; i<money.length-1; i++){
            dp1[i] = Math.max(dp1[i-1], money[i] + dp1[i-2]);
            if(max1 < dp1[i])max1 = dp1[i];
        }
        
        //마지막 집은 터는 경우
        
        int [] dp2 = new int[money.length];
        dp2[0] =0;
        dp2[1] = money[1];
        int max2=-1;
        
        for(int i=2; i<money.length; i++){
            dp2[i] = Math.max(dp2[i-1],money[i] + dp2[i-2] );
            if(max2<dp2[i])max2=dp2[i];
        }
        
        return Math.max(max1, max2);
    }
}