
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        if(tc==0){
            System.out.println(0);
            return;
        }
        int[] store = new int[tc];
        //절사평균 구하기
        int del = (int) Math.round(tc * (0.15));

        for (int i = 0; i < store.length; i++) {
            int x = Integer.parseInt(br.readLine());
            store[i] = x;
        }
        Arrays.sort(store);

        int sum =0;
        for(int i=del; i<= store.length-del-1; i++){
            sum+=store[i];
        }
        // Calculating average as double to prevent integer division issues
        double average = (double) sum / (store.length - (del * 2));
        int answer = (int) Math.round(average);
        System.out.println(answer);

    }
}
