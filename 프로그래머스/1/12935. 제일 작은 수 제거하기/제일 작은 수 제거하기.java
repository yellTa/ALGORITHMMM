import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int[] arr) {
        
        if(arr.length == 1){
            ArrayList<Integer> a = new ArrayList<>();
            a.add(-1);
            return a;
        }
        
        
        ArrayList<Integer> min = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        for(int i : arr){
            result.add(i);
            min.add(i);
        }
        Collections.sort(min, Collections.reverseOrder());
        
    
        result.remove(Integer.valueOf(min.get(min.size()-1)));

        return result;
    }
}