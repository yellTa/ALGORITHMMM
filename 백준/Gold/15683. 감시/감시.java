import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static int N, M;
    static ArrayList<int[]> cctv;

    static int arr[][];

    static int answer;

    static int dx[] = {-1,0,1,0};
    static int dy[] = {0,1,0,-1};

    public static void supervisor(int x, int y, int dir){
        dir = dir%4;
        int nx = x;
        int ny = y;
        while(true){

            nx += dx[dir];
            ny += dy[dir];

            if(nx<0 || ny<0 || nx>=N || ny>=M)return;
            if(arr[nx][ny] ==6) return;
            if(arr[nx][ny] !=0) continue;
            arr[nx][ny] =8;
        }

    }
    public static void dfs(int depth){
        if(depth ==cctv.size()){
            int count=0;
            for(int i=0; i<N; i++){
                for(int k=0; k<M; k++){
                    if(arr[i][k] ==0)count++;
                }
            }
            answer = Math.min(answer, count);
            return;
        }

        int x = cctv.get(depth)[0];
        int y = cctv.get(depth)[1];

        int temp[][] = new int[N][M];

        for(int dir=0; dir<4; dir++){
            for(int i=0; i<N; i++){
                for(int k=0; k<M; k++){
                    temp[i][k] = arr[i][k];
                }
            }

            if(arr[x][y] ==1){

                supervisor(x,y,dir);
            }else if(arr[x][y] ==2){
                supervisor(x,y,dir+1);
                supervisor(x,y,dir+3);
            }else if(arr[x][y] ==3){
                supervisor(x,y,dir);
                supervisor(x,y,dir+1);
            }else if(arr[x][y] ==4){
                supervisor(x,y,dir);
                supervisor(x,y,dir+1);
                supervisor(x,y,dir+3);
            }else if(arr[x][y] ==5){
                supervisor(x,y,dir);
                supervisor(x,y,dir+1);
                supervisor(x,y,dir+2);
                supervisor(x,y,dir+3);
            }
            dfs(depth+1);

            for(int i=0; i<N; i++){
                for(int k=0; k<M; k++){
                    arr[i][k] = temp[i][k];
                }
            }
        }
    }


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        cctv = new ArrayList<>();
        answer=Integer.MAX_VALUE;
        arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int k = 0; k < M; k++) {
                arr[i][k] = Integer.parseInt(st.nextToken());
                if (arr[i][k] != 0 && arr[i][k] != 6) {
                    cctv.add(new int[]{i, k});
                }
            }
        }

        dfs(0);

        System.out.print(answer);
    }
}