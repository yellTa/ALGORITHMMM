import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    private static int find(int x, int n, int[] arr){
        int st =0;
        int en =n-1;

        while(st<=en){
            int mid= (st+en)/2;
            if(arr[mid] <x){
                st = mid +1;
            }else if(arr[mid] >x){
                en = mid-1;
            }else return 1;
        }
        return 0;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i=0; i< n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(arr);
        
        int m = Integer.parseInt(br.readLine());

        //정답ㅇ르 StringBuilder for return 
        
        StringBuilder sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<m; i++){
            
            int x = Integer.parseInt(st.nextToken());

            sb.append(find(x,n, arr)).append("\n");
        }
        System.out.println(sb);
    }
}