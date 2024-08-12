import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] d= new int[20];


    public static void main(String[] args) throws IOException {


        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        for (int i = 4; i <= 11; i++) {
            d[i] = d[i - 3] + d[i - 2] + d[i - 1];
        }

        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc != 0) {
            int x = sc.nextInt();
            System.out.println(d[x]);
            tc--;


        }
    }
}