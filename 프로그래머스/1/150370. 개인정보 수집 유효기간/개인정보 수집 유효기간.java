import java.util.*;


class Solution {
    static int[] terms = new int[30];
    
    private static int make(String[] todays, String[] date, String term){

        int year= Integer.parseInt(date[0]);
        int month = Integer.parseInt(date[1]);
        int days = Integer.parseInt(date[2]);
        //약관을 월에 더하기
        month = month + (terms[term.charAt(0)-'A']);
        //하루 빼기
        
        
        
        //달이 넘어가는 경우
        year += (month - 1) / 12;
        month = (month - 1) % 12 + 1;
        
        //1일인 경우 28로 바꾸고 달에서 1개 빼주기 그럼 31일 30일 고려 안해도 됨
        days--;
        if(days==0){
            days=28;
            month--;
            if(month==0){
                year--;
                month=12;
            }
        }
        
        System.out.println(year+ " "+ month + " "+ days);
        
        int toyear = Integer.parseInt(todays[0]);
        int tomonth = Integer.parseInt(todays[1]);
        int toda = Integer.parseInt(todays[2]);
            
        //오늘 날짜랑 비교하기        
        if(year<toyear)return 1;//파기
        if ( year==toyear &&month<tomonth)return 1;
        if(year==toyear && month==tomonth&&days<toda)return 1;

        return 0; //0이면 파기 x
    }
    
    public ArrayList<Integer> solution(String today, String[] t, String[] p) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        
        //약관 배열만들기
        for(int i=0; i<t.length; i++){
            String[] temp = t[i].split(" ");
            terms[temp[0].charAt(0) - 'A'] = Integer.parseInt(temp[1]);
        }
        
        for(int i=0; i<p.length; i++){
            String [] temp = p[i].split(" ");
            String [] date =temp[0].split("\\.");
            String term = temp[1];
            String []todays = today.split("\\.");
            
            int x = make(todays, date, term);
            if(x==1) answer.add(i+1);
        }
        
        
        return answer;
    }
}