import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String[] a2 = a.split("");
        
        for(String b : a2){
            System.out.println(b);
        }
    }
}