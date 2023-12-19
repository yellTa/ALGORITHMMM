import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer token = new StringTokenizer(bf.readLine());
        
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while(token.hasMoreTokens()){
           arr.add(Integer.parseInt(token.nextToken()));
        }
        
        int re = arr.get(0) - arr.get(1);
        
        bw.write(Integer.toString(re));
        bw.flush();
        bw.close();
    }
            
        
}