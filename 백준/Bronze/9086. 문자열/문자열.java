import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        while(tc !=0){
            String s = br.readLine();
            String start = s.substring(0, 1);
            String end = s.substring(s.length()-1, s.length());

            System.out.println(start+end);
            tc--;
        }

    }
}