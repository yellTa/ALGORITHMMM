import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int w=0;
    static int h=0;
    //홀수
    static int []odx ={0,-1,0,1,1,1};
    static int []ody={-1,0,1,1,0,-1};

    //짝수
    static int[] edx={-1,-1,-1,0,1,0};
    static int[]edy={-1,0,1,1,0,-1};

    static int[][] board = new int[110][110];

    private static void outWall(int []arr){
        Queue<int[]> q = new LinkedList<>();
        q.add(arr);

        //외벽 방문여부 check 배열
        boolean[][] visited = new boolean[110][110];

        visited[arr[0]][arr[1]] = true;

        while(!q.isEmpty()){
            int []cur = q.poll();

            board[cur[0]][cur[1]] = 2;//외벽 2로 표시

            for(int i=0; i<6; i++){
                int nx = cur[0] + (cur[1]%2==0? edx[i] : odx[i]);
                int ny = cur[1] + (cur[1]%2 ==0? edy[i]: ody[i]);

                if(nx<1 || nx> w ||ny<1 || ny >h || visited[nx][ny] == true || board[nx][ny] ==1)continue;
                q.add(new int[]{nx,ny});
                visited[nx][ny]= true;
            }
        }

    }

    static int answer=0;
    static boolean[][] visited = new boolean[110][110];
    private static void countWall(int[] arr){
        Queue<int []> q = new LinkedList<>();

        q.add(arr);
        visited[arr[0]][arr[1]] = true;

        while(!q.isEmpty()){
            int [] cur = q.poll();

            for(int i=0; i<6; i++){
                int nx = cur[0] + (cur[1]%2==0? edx[i] : odx[i]);
                int ny = cur[1] + (cur[1]%2 ==0? edy[i] : ody[i]);

                if(nx <1 || ny < 1 || nx>w || ny >h || board[nx][ny] ==2){
                    answer++;
                    //범위를 넘어선 곳의(그러니까 외곽이랑 붙은 쪽의 로직임)
                    continue;
                }
                if(board[nx][ny] ==1 || visited[nx][ny] ==true)continue; //벽이니까 컨티뉴

                visited[nx][ny] = true;
                q.add(new int[]{nx,ny});

            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st  = new StringTokenizer(br.readLine());

            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

        //보드 받기
        for(int i=1; i<=h; i++){//열
            st = new StringTokenizer(br.readLine());
            for(int k=1; k<=w; k++){//행
                board[k][i] = Integer.parseInt(st.nextToken());
            }
        }

        //외부벽 카운트하기
        for(int i=1; i<=h; i++){
            for(int k=1; k<=w; k++){
                if(board[k][i] == 0 && (i == 1 || k == 1 || i == h || k == w)){
                    outWall(new int[]{k,i});
                }
            }
        }


        //건물이랑 닿는 곳 체크하기
        for(int i=1; i<=h; i++){
            for(int k=1; k<=w; k++){
                if(board[k][i] == 1)countWall(new int[]{k,i});
            }
        }

        System.out.println(answer);


    }




}