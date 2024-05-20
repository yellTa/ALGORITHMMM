import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    /*
    *
    *
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a[] = new int[5];
        int sum=0;
        for(int i=0; i<5; i++){
            int x = Integer.parseInt(br.readLine());
            a[i] = x;
            sum +=x;
        }
        int avg = sum/5;
        Arrays.sort(a);
        int mid = a[2];
        System.out.print(avg + "\n" + mid);


    }
}