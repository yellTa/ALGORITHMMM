import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
//         int answer = 0;
        
//         ArrayList<Integer> sort  = new ArrayList<Integer>();
        
//         for(int s : d){
//             sort.add(s);
//         }  
        
//         Collections.sort(sort);
        
//         for(int i=0 ;i<sort.size(); i++){
//             answer += sort.get(i);
            
//             if(answer > budget){
//                 answer =i;
//                 break;
                
//             }else if (answer == budget){
//                 answer = i+1;
//             }
//         }
         int answer = 0;
        // 정답 변수 선언 및 0으로 초기화
        Arrays.sort(d);
        // 작은 수가 앞에 오게 배열 정렬
 
        for (int i = 0; i < d.length; i++) {
            // 배열 끝까지 도는데
            if (d[i] <= budget) {
                // 부서가 신청한 예산이 총예산 잔액보다 작으면
                budget -= d[i];
                // 총예산에서 그만큼 빼고
                answer++;
                // 정답 카운트 올린다
            } else {
                // 부서가 신청한 예산이 총예산잔액보다 큰 순간이 오면
                break;
                // 더이상의 반복은 무의미하니까 break;
            }
        }
 
        return answer;
        // 지원해 줄 수 있는 부서의 최대 값
    }
}