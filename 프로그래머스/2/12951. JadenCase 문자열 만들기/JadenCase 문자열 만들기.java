class Solution {
    public String solution(String s) {
        
        char[] array = s.toCharArray();
        
        boolean flag= true;

        //소문자 구하려면 32 더하고
        //대문자는 32빼기
        
        //65이상90 이하 A Z
        //97 122 a부터 z
        
        for(int i=0; i<s.length(); i++){
            int x = array[i];
            if(flag==true){
               
                if(x>=97 && x<=122){
                    x = x-32; //대문자로 바꾸기 
                }
                flag =false;
                
                array[i]=(char)x;
                
            }else{
                if(x>=65 && x<=90){
                    x +=32;
                    array[i]= (char)x;
                }
            }
            
            if(array[i]==' '){
                flag = true;
            }
            
        }
        
        return new String(array);
    }
}