import java.util.*;

class Solution {
    public int[] solution(int[] l, int[] win_nums) {
        int[] answer = new int[2];
        //몇등인지 뽑아내려는 배열
        int[] winner = new int[7];
        int win=5;
        for(int i=2; i<=6; i++){
            winner[i] = win;
            win--;
        }
        
        Integer [] lottos=new Integer[6];
        
        for(int i=0; i<6; i++){
            lottos[i] = l[i];
        }
        //로또 번호 정렬
        Arrays.sort(lottos,(a,b) -> a-b);
        
        int[] result = new int[46];
        //win_num counting sort저장
        for(int x : win_nums){
            result[x] =1;
        }
        
        int zCount=0;
        int count=0;
        for(int x : lottos){
            if(x==0)zCount++;
            if(result[x] ==1)count++;
        }
        
        //최저 점수 : count 점수
        //최고 등수 : count+ zCount의 등수
        answer[0] = winner[count+zCount]==0? 6:winner[count+zCount];
        answer[1] = winner[count] ==0? 6:winner[count];
   
        return answer;
    }
}