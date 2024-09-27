import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc=  new Scanner(System.in);
        int n = sc.nextInt();

        int count=0;
        int idx=0;
        while(true){
            idx++;
            if(Integer.toString(idx).contains("666")){
                count++;
                if(count ==n) {
                    System.out.println(idx);
                    break;
                }
            }
        }
    }
}