import java.util.*;

class Solution {
    static Set<Integer> set;
    static int isused[] = new int[10];
    
    private void type(String numbers, String s, int depth){
        if(depth > numbers.length()) return;
        
        for(int i=0; i<numbers.length(); i++){
            if(isused[i] ==0){
                isused[i] =1;
                set.add(Integer.parseInt(s+numbers.charAt(i)));
                type(numbers, s+numbers.charAt(i), depth+1);
                isused[i] =0;
            }    
        }
    }
    
    private static boolean isPrime(int n){
        if(n<2)return false;
        
        for(int i=2; i<= (int)Math.sqrt(n); i++){
            if(n%i ==0)return false;
        }
        return true;
    }
    
    public int solution(String numbers) {
        int answer = 0;
        set = new HashSet<>();
        
        type(numbers, "" ,0);
        
        for(int i: set){
            if(isPrime(i))answer++;
        }
        
        return answer;
    }
}