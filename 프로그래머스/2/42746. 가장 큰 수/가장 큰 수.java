import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String arr[] = new String[numbers.length];
        for(int i=0; i<numbers.length; i++){
            arr[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(arr, (a,b)->{
            int A = Integer.parseInt(a+b);
            int B = Integer.parseInt(b+a);
            //내림차순으로 정렬해야하니까
            return Integer.compare(B,A);
        });
        
        for(int i=0; i<numbers.length ;i++){
            if(arr[0].equals("0")) return "0";
            answer += arr[i];
        }

        return answer;
    }
}