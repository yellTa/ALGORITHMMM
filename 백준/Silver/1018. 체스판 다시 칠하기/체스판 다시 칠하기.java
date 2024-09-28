import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());

        String board[] = new String[row];

        for(int i=0; i<row; i++){
            board[i] = br.readLine();
        }
        int sol = Integer.MAX_VALUE;

        for(int i=0; i<=row -8; i++){
            for(int j=0; j<=col-8; j++){
                int curSol = solved(i, j, board);
                sol = Math.min(sol, curSol);
            }
        }
        System.out.println(sol);

    }

    public static int solved(int start_row, int start_col, String board[]){
       String orgBoard[] = {"WBWBWBWB", "BWBWBWBW"};
       int whiteSol=0;

       for(int i=0; i<8; i++){
           int row = start_row +i;
           for(int k=0; k<8; k++){
               int col = start_col +k;

               if(board[row].charAt(col) != orgBoard[row%2].charAt(k)){
                   whiteSol++;
               }
           }
       }
        return Math.min(whiteSol, 64 - whiteSol);

    }

}