import java.util.*;
import java.io.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        HashMap<String, Integer> hash = new HashMap<String,Integer>();
        
        for(String s : phone_book){
            hash.put(s,1);
        }
        
        for(int i=0; i<phone_book.length; i++){
            String numbers="";
            for(int j=0; j<phone_book[i].length(); j++){
                numbers += phone_book[i].substring(j,j+1);
                if(hash.containsKey(numbers) && !numbers.equals(phone_book[i])){
                   
                    return false;
                }
            }
          
        }
        
        
        return answer;
    }
}