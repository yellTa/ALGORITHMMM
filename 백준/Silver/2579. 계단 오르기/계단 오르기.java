import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());
        int [] s = new int[tc+10];
        for(int i=0; i< tc; i++){
            s[i+1] = Integer.parseInt(br.readLine());
        }

        int d[][] = new int[330][3];

        d[1][1] = s[1];
        d[1][2] = 0;

        d[2][1] = s[2];
        d[2][2] = s[1] + s[2];

        for(int i=3; i<=tc; i++){
            d[i][1] = Math.max(d[i-2][1], d[i-2][2])+s[i];
            d[i][2] = d[i-1][1] + s[i];
        }
        System.out.println(Math.max(d[tc][1], d[tc][2]));
    }
}