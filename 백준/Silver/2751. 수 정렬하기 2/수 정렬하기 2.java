import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        List<Integer> store = new ArrayList<>();
        for(int i=0; i<tc; i++){
            int x = Integer.parseInt(br.readLine());
            store.add(x);
        }

        Collections.sort(store);

        StringBuilder sb = new StringBuilder();
        for(int x : store){
            sb.append(x).append("\n");
        }
        System.out.println(sb);


    }
}