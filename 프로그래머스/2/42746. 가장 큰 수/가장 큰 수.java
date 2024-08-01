import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String arr[] = new String[numbers.length];
        for(int i=0; i<numbers.length; i++){
            arr[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(arr, (a,b)->{
            //내림차순으로 정렬해야하니까
            return (b+a).compareTo(a+b);
        });
        
        for(int i=0; i<numbers.length ;i++){
            if(arr[0].equals("0")) return "0";
            answer += arr[i];
        }

        return answer;
    }
}