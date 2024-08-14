
import java.util.Scanner;

public class  Main {


    public static void main(String[] args) {
        //1,2,3,4를 이용하여 세 자리 자연수를 만드는 방법 순서 x 중복 x

        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt(); // 행
        int y = sc.nextInt(); // 열

        int [][] tri = new int[50][50];

        tri[1][1] = 1;
        tri[2][1]=1;
        tri[2][2] = 1;

        for(int i=3; i<= x; i++){
            tri[i][1] = 1;

            for(int k=2; k<=x-1; k++){
                tri[i][k] = tri[i-1][k] + tri[i-1][k-1];
            }
            tri[i][x] = 1;
        }

        System.out.println(tri[x][y]);

    }
}
