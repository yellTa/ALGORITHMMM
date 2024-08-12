import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] d= new int[10000005];


    public static void main(String[] args) throws IOException{

        Scanner sc = new Scanner(System.in);
        d[1] = 0;
        int x = sc.nextInt();

        for(int i=2; i<=x; i++){
            d[i] = d[i-1]+1;
            if(i%2==0) d[i] = Math.min(d[i] , d[i/2]+1);
            if(i%3 ==0) d[i] = Math.min(d[i] ,d[i/3]+1);
        }

        System.out.println(d[x]);

    }

}