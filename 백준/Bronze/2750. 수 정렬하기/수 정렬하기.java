import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        int[] answer = new int[tc];

        for(int i=0; i< tc; i++){
            answer[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(answer);

        for(int i=0; i< tc; i++){
            System.out.println(answer[i]);
        }
    }
}