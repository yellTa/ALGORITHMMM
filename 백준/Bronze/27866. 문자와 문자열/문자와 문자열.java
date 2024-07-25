import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s= br.readLine();
        int idx = Integer.parseInt(br.readLine());

        char[] array = s.toCharArray();
        System.out.println(array[idx-1]);


    }
}