import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        //divide by space
        
        String[] array= s.split("");
        
        int index =1;
        for(String str : array){
            if(str.equals(" ")){
                //skip it 
                index =1;
                answer += str;
                
            }else if(index%2 ==0 ){
                str=str.toLowerCase();
                answer += str;
                index++;
            }else if(index%2 !=0){
                str = str.toUpperCase();
                answer +=str;
                index++;
            }
        }
        
        
//         for(String str : array){
//             for(int i=0; i <str.length(); i++){
//                 if((i+1)%2 !=0){
//                     String a = Character.toString(str.charAt(i)).toUpperCase();
//                     answer += a;   
//                 }else{
//                     answer += Character.toString(str.charAt(i)).toLowerCase();
//                 }
            
//             }
//             answer += " ";
            
//         }
        return answer;
   }
}  