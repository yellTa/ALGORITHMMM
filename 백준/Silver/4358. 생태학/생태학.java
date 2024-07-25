import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        TreeMap<String, Integer> myMap = new TreeMap();
        int count =0;
        while(true){
            String s = br.readLine();

            if(s == null || s.length()==0)break;

            count++;

            if(myMap.containsKey(s)){
                int x = myMap.get(s);
                myMap.put(s,x+1);
            }else myMap.put(s,1);

        }

        for(String s: myMap.keySet()){
            double x = (double)myMap.get(s);
            double result = (x/count)*100;

            String number = String.format("%.4f", result);

            System.out.println(s+" "+ number);
        }

    }
}