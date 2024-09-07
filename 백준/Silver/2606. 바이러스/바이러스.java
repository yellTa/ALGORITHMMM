import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.*;

class Main {
    static int [] vis;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int V = Integer.parseInt(br.readLine());
        vis= new int[N+1];


        //인접 행렬
        int[][] arr = new int[N+1][N+1];

        StringTokenizer st;
        //인접 리스트 활용 예정

        for(int i=0; i<V; i++){
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            //무방향 인접 행렬 생성
            arr[x][y]=1;
            arr[y][x]=1;
        }

        find(1, arr);

        int answer=0;

        for(int x : vis){
            if(x==1){
                answer++;
            }
        }
        System.out.println(--answer);
    }

    private static void find(int start, int[][] arr){
      vis[start]=1;

      for(int i=0; i<arr.length;i++){
          if(arr[start][i]==1 && vis[i]==0){//start번의 행과 연결된 노드가 있고 해당 노드가 검사를 안한 친구라면?
              find(i,arr);
          }
      }
    }

}