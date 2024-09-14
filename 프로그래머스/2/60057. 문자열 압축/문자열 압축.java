import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        //쪼개기 문자열 만들기
        
        String tempAnswer="";
        
        if(s.length()==1)return 1;
        
        Stack<String> stack = new Stack<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=1; i<=s.length()/2; i++){ //1번부터 length/2까지 쪼갤예정
            //i는 쪼개는 숫자가 된다. 
            //default값 지정
            
            for(int k=0; k<s.length(); k +=i){
                int x = Math.min(k+i, s.length());
                String temp = s.substring(k,x);
                
                if(stack.isEmpty()){
                    stack.push(temp);
                    continue;
                }
                if(stack.peek().equals(temp)){
                    stack.push(temp);
                    
                }else{//다른게 들어온 경우
                    if(!stack.isEmpty()){
                        String word = stack.peek();
                        int size = stack.size();
                        
                        if(size ==1){
                            tempAnswer += word;
                        }else{
                            tempAnswer +=(stack.size())+word;
                        }
                    }
                    
                    stack.clear();
                    stack.push(temp);
                }
                // System.out.print(s.substring(k,x)+ " "); 
            }
            //마지막을 Stack에 남은 값 까지 더해줌
            if(!stack.isEmpty()){
                String word = stack.peek();
                int size = stack.size();
                if(size ==1)tempAnswer +=word;
                else tempAnswer +=(stack.size())+word;
            }
            stack.clear();
            pq.add(tempAnswer.length());
            
            tempAnswer="";
            // System.out.println();
        }
        
        
        return pq.poll();
    }
}