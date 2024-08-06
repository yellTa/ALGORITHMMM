import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static int x = 0;
    static int y=0;
    static int arr[] = new int[10];
    static boolean isused[] = new boolean[10];

    private static void func(int k){
        if(k==y){
            for(int i=0; i<y; i++){
                System.out.print(arr[i]+ " ");
            }
            System.out.println();
            return;
        }

        for(int i=1; i<=x; i++){
            if(!isused[i]){
                arr[k] =i;
                isused[i] =true;
                func(k+1);
                isused[i] =false;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        func(0);


    }
}