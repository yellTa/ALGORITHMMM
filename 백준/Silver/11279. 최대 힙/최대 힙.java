import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;

        int tc = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i=0; i<tc; i++){
            int command = Integer.parseInt(br.readLine());

            if(command ==0){
                if(!pq.isEmpty()){
                    System.out.println(pq.poll());
                    continue;
                }

                System.out.println(0);
            }else{
                pq.add(command);
            }

        }
    }
}