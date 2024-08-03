import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static Map<Integer, Integer> mp = new TreeMap<>();
    static int idx=0;

    private static int find(int x, int[] arr){
        int st = 0;
        int en = idx-1;

        while(st<=en){
            int mid = (st+en)/2;
            
            if(arr[mid] < x){
                st = mid +1;
            }else if(arr[mid] >x){
                en = mid-1;
            }else {
                return mp.get(arr[mid]);
            }
        }
        return 0;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0; i<n; i++){
            int x = Integer.parseInt(st.nextToken()); 
            if(mp.containsKey(x)){
                mp.put(x, mp.get(x)+1);
            }else {
                mp.put(x,1);
            }
        }

        int arr[] = new int[mp.size()];
        for(Map.Entry<Integer,Integer> mx : mp.entrySet()){
            arr[idx] = mx.getKey();
            idx++;

        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<m; i++){
            int x = Integer.parseInt(st.nextToken());

            sb.append(find(x, arr)).append(" ");
        }
        System.out.println(sb);


    }
}