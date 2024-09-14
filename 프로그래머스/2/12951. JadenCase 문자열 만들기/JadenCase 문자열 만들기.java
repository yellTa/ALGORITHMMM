class Solution {
    //소문자 97~ 122
    //대문자 65~ 90 A to Z
    public String solution(String s) {
        String answer ="";
        s = s.toLowerCase();
        
        char[] c = s.toCharArray();
        
        //첫글자를 대문자로
        if(c[0]<=122 && c[0]>=97){
            int x  =c[0];
            x = x-32; //대문자로 바꿈
            c[0] = (char)x;
        }
        
        //나머지 문자를 계산하기
        boolean flag = false;
        
        for(int i=0; i< c.length; i++){
            if(c[i] ==' '){
                flag = true;
            }else if(flag&& c[i]<=122 && c[i] >=97){//공백 다음 문자에 도달한 경우 
                flag = false;
                
                int x  = c[i];
                x =x-32;
                c[i] =(char)x;
            }else flag = false;
        
        }
        
        return new String(c);
    }
}