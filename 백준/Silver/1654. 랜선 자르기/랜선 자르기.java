
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int store[] = new int[K];

        for(int i=0 ;i< store.length; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());

            store[i] = x;
        }
        Arrays.sort(store);

        long len = store[store.length-1];//가장 긴 길이

        long start =1;
        long end =len;

        long result =0;
        while(start<=end){
            long mid = (start+end)/2;
            //랜선 개수 찾기
            long count= find(mid,store);

            if(count>=N){
                result = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        System.out.println(result);
    }
    private static long find(long mid, int[] store){
        long result =0;
        for(int i=0; i<store.length; i++){
            result += store[i]/mid;
        }
        return result;

    }
}
