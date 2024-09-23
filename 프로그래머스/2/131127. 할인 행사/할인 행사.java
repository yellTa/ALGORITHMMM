import java.util.*;

/*
조건
10일동안 회원 자격 부여
회원 대상 매일 한 가지 제품 할인 -> 하루에 하나씩만 구매

입력
정현이가 원하는 제품 want 원하는 수량 number
xyz마트에서 할인하는 제품 문자열 discount

제한
want<= 10개
1<= number<=10 원소 합 10개

10<=discount<=10^6 -> n^2 안됨
*/

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        //1. want map 만들기
        Map<String, Integer> wantMap = new HashMap<>();
        for(int i=0;i <want.length; i++){
            wantMap.put(want[i], number[i]) ;
        }
        
       //2. make a box(size 10)
        Map<String,Integer> boxMap = new HashMap<>();
       for(int i=0; i<10; i++){
           boxMap.put(discount[i], boxMap.getOrDefault(discount[i],0)+1);
       } 
    
        //3 compare by days
        for(int i=0; i<=discount.length -10; i++){
            //3.1 compare wantMap and boxMap
            boolean next=true;
            
            for(Map.Entry<String,Integer> store : wantMap.entrySet()){
                int wantCount = store.getValue();
                int boxCount = boxMap.getOrDefault(store.getKey(), 0);
                
                if(wantCount !=boxCount){
                    next = false;
                    break;
                }
                
            }
            if(next){//날짜를 증가시키는 방향으로
                answer++;
            }
            
            //box 이동시키기
            if(i + 10 <discount.length){
                //뺴주기
                boxMap.put(discount[i],boxMap.get(discount[i])-1);
                if(boxMap.get(discount[i])==0){
                    boxMap.remove(discount[i]);
                }
                
                boxMap.put(discount[i+10], boxMap.getOrDefault(discount[i + 10], 0) +1);
            }
            
        }
        
        return answer;
    }
    
    private Map<String,Integer> prepareBox(String[] discount, int i, Map<String, Integer> boxMap){
        
        boxMap.put(discount[i-1], boxMap.getOrDefault(discount[i-1],1) -1);
        boxMap.put(discount[i+9], boxMap.getOrDefault(discount[i+9], 0)+1);
        
        return boxMap;
    }
    
}