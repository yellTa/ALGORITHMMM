import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Queue<int[]> q1 = new LinkedList<>();
        Queue<int[]> q2 = new LinkedList<>();
        
        long object=0L;
        long sum1=0L;
        long sum2=0L;
        
        for(int i=0; i<queue1.length; i++){
            object += queue1[i] + queue2[i];
            sum1 += queue1[i];
            sum2 += queue2[i];
            
            q1.add(new int[]{i,queue1[i],1});
            q2.add(new int[]{i,queue2[i],2});
        }
        
        if(object%2 !=0) return -1;
        //예외 처리
        object = object/2;
        for(int i=0; i<queue1.length; i++){
            if(queue1[i]>object || queue2[i]>object) return -1;
        }
        
        int count=0;
        int c1=0;
        int c2=0;
        while(true){
            if(sum1 == object)return count;
            count++;

            if(sum1<object){
                int[] x = q2.poll();
                if(x[0] ==0 && x[2]==2){
                    c2++;
                    if(c2==2) return -1;
                }
                q1.add(x);
                sum2 -=x[1];
                sum1 +=x[1];
            }else{
                int[] x =q1.poll();
                if(x[0]==0 && x[2]==1){
                    c1++;
                    if(c1==2)return -1;
                }
                sum1 = sum1-x[1];
                sum2 = sum2+x[1];
                q2.add(x);
            }

        }
    }
}