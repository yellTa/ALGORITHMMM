import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        int [] arr = new int[1000010];

        for(int i=0; i<tc; i++){
            int x = Integer.parseInt(st.nextToken());
            arr[x] = 1;
        }

        int target = Integer.parseInt(br.readLine());
        int answer=0;

        for(int i=1; i<=target/2; i++){
            if(arr[i] ==1 && target-i <=1000000 && target-i >0  && arr[target-i] ==1 && i  !=target-i){
                answer++;
            }
        }
        System.out.println(answer);
    }
}