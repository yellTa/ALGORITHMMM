import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static int[] n;
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int  N = Integer.parseInt(br.readLine());

        n = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0; i< N; i++){
            n[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(n);

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<M; i++){
            int x = Integer.parseInt(st.nextToken()) ;

            int answer = find(x);
            System.out.print(answer + " ");
        }

    }

    public static int find(int target){
        int start =0;
        int end = n.length-1;

        while(start<=end){
            int mid = (start + end)/2;

            if(n[mid] < target){
                start = mid+1;
            }else if(n[mid] > target){
                end = mid-1;
            }else if(n[mid] == target){
                return 1;
            }
        }
        return 0;
    }

}