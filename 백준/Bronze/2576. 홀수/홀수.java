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

        int a[] = new int[7];

        for(int i=0; i<7; i++){
            int num = Integer.parseInt(br.readLine());
            a[i] = num;
        }

        Arrays.sort(a);

        int count =0;
        Boolean flag = false;
        String answer = "";

        int sum=0;
        int min=0;

        for(int i=0; i<7; i++){
            if(a[i]%2 ==1){
                flag =true;
                sum += a[i];
                count++;

                if(count == 1){
                    min = a[i];
                }
            }
        }

        if(!flag)System.out.println(-1);

        else System.out.print(sum + "\n" + min);
    }
}