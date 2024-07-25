import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Main {
    private static boolean isRight(String s){
        int start = 0;
        int end = s.length()-1;

        while(start<=end){
            if(s.charAt(start) != s.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        int answer = s.length();
        for(int i=0; i<s.length(); i++){
            //팰린드롬 체크 로직
            if(isRight(s.substring(i)) == true) break;
            answer++;
        }

        System.out.println(answer);
    }
}