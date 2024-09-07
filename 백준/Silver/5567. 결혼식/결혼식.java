import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.*;

class Main {
    static int [] vis;
    static ArrayList<Integer> store;
    static int count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int V = Integer.parseInt(br.readLine());
        vis = new int[N+1];
        store = new ArrayList<>();

        int [][] arr = new int[N+1][N+1];

        for(int i=0; i<V;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            arr[x][y] =1;
            arr[y][x]=1;
        }
        count=0;
        find(1,arr);

//        for(int x : vis){
//            System.out.print(x + " ");
//        }
        System.out.println(--count<0? 0 : count );
    }


    private static void find(int start,int [][] arr){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        int depth=0;
        while(!q.isEmpty() && depth<2){

            int size = q.size();
            depth++;

            for(int i=0;i <size ;i++){
                int cur = q.poll();

                for(int k=1; k<arr.length; k++){
                    if(arr[cur][k] ==1 && vis[k]==0){
                        vis[k]=1;
                        q.add(k);
                        count++;
                    }
                }
            }
        }

    }

}