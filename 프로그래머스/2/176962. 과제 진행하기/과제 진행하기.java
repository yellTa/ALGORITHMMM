import java.util.*;

class Solution {
    public ArrayList<String> solution(String[][] plans) {
        ArrayList<String> answer = new ArrayList<>();
        
        //시간 순 정리하기
        
        //A. idx 시간 맵 만들기
        Map<Integer, Integer> timeMap = new HashMap<>();
        
        for(int i=0; i< plans.length; i++){
            String temp= plans[i][1].replace(":","");
            int time = Integer.parseInt(temp);
            timeMap.put(i,time);
        }
        
        //결과 확인
        //B. 시간순으로 정렬하기 
        List<Map.Entry<Integer, Integer>> sorted = new ArrayList<>(timeMap.entrySet());
        Comparator<Map.Entry<Integer, Integer>> compare = new Comparator<>(){
          @Override
            public int compare(Map.Entry<Integer, Integer> a, Map.Entry<Integer,Integer> b){
                return a.getValue().compareTo(b.getValue());
            }
        };
        
        Collections.sort(sorted, compare);
        
        //2. 정리한 내용 배열로 만들기 sortResult
    
        String[][] sortResult = new String[plans.length][3];
        int idx=0;
        for(Map.Entry<Integer, Integer> a : sorted){
            sortResult[idx] = plans[a.getKey()];
            idx +=1;
        }
        
        //3.공부해서 끝내는 값 먼저 넣기
        Stack<String[]> stack = new Stack<>();
        stack.push(sortResult[0]); //첫 초기값 수행
        
        for(int i=1; i<sortResult.length; i++){
            int gap = timeGap(stack.peek(), sortResult[i]);
            int peekTime = Integer.parseInt(stack.peek()[2]);
            
            while(!stack.isEmpty() && gap>=peekTime){
                gap -= peekTime; //작업을 수행하고 남은 시간
                answer.add(stack.pop()[0]);
                
                if(!stack.isEmpty()){
                    peekTime = Integer.parseInt(stack.peek()[2]);
                }
            }
            
            //남는 작업시간 갱신
            if(!stack.isEmpty()){
                String[] top = stack.pop();
                top[2] = Integer.toString(peekTime-gap);
                stack.push(top);
            }
            
            stack.push(sortResult[i]);
        }
       
        
        while(!stack.isEmpty()){
            answer.add(stack.pop()[0]);
        }
        
        return answer;
    }
    
    private int timeGap(String [] a, String[] b){
        //b에서 a를 빼야됨
        String[] Atime = a[1].split(":");
        String[] Btime = b[1].split(":");
        int hour = Integer.parseInt(Btime[0])- Integer.parseInt(Atime[0]);
        int min = Integer.parseInt(Btime[1]) - Integer.parseInt(Atime[1]);
        
        
        return hour*60 + min;
    }
}