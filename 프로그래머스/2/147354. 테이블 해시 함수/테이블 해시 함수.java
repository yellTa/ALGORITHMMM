import java.util.*;

class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        //1. Do sort according to col's number
        
        //A. AHSH 쌍 만들기
        HashMap<Integer, int[]> pairMap= new HashMap<>();
        
        for(int i=0; i< data.length; i++){
            pairMap.put(i, data[i]);
        }
        
        // Map.Entry 리스트로 변환
        List<Map.Entry<Integer, int[]>> entries = new ArrayList<>(pairMap.entrySet());
        
        //정렬 로직 구현
        Comparator<Map.Entry<Integer, int[]>> compared = new Comparator<Map.Entry<Integer, int[]>>(){
         @Override
          public int compare(Map.Entry<Integer, int[]> e1, Map.Entry<Integer, int[]> e2){
              int[] arr1 = e1.getValue();
              int[] arr2 = e2.getValue();
              
              if(arr1[col-1] == arr2[col-1]){
                  return Integer.compare(arr2[0], arr1[0]);
                  
              }
                  return Integer.compare(arr1[col-1], arr2[col-1]);
          }  
        };
        
        //정렬
        Collections.sort(entries, compared);
        
        //2. 정렬된 데이터 s_i i번째 행 나머지 MOD연산의 합 구하기
        int start=0;
        int newValue=0;
        //초기값 설정
        int n1=0;
        int n2=0;
        for(Map.Entry<Integer, int[]> en : entries){
            start++;
            if(start == row_begin){//S_i 구하기
                n1 = makeSi(start, en.getValue());
            }else if(start > row_begin){
                n2 = makeSi(start, en.getValue());
                //xor 연산 수행
                newValue = n1^n2;
                n1 = newValue;
                
                if(start == row_end){
                    break;
                }
            }
          
        }
        
        
        return newValue;
    }
    
    private int makeSi(int start, int[] arr){
        
        int sum=0;
        
        for(int i=0; i< arr.length; i++){
            sum += arr[i]%start;
        }
        return sum;
        
    }
}