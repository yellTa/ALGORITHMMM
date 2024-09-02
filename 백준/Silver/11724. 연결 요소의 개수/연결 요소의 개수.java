import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N;
    static int V;
    static int []node;
    static ArrayList<ArrayList<Integer>> map;

    private static void bfs(int start){
        Queue<Integer> q = new LinkedList<>();

        q.add(start);
        node[start]=1;

        while(!q.isEmpty()){
            int cur = q.poll();
            ArrayList<Integer> arr = map.get(cur);

            for(int x : arr){//연결되어 있는 노드들
                if(node[x] !=1){//검사한 노드가 아닌경우
                    node[x] =1;
                    q.add(x);
                }
            }

        }

    }

    public static void main(String[] args) throws IOException {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         StringTokenizer st = new StringTokenizer(br.readLine());

         N = Integer.parseInt(st.nextToken());
         V = Integer.parseInt(st.nextToken());

         node = new int[N+1];
        map  = new ArrayList<>();
        //map 초기화하기
        for(int i=0; i<=N; i++){
            map.add(new ArrayList<Integer>());
        }

         //인접 리스트 만들기
        for(int i=0; i<V; i++){
            st = new StringTokenizer(br.readLine());
            int node = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());

            map.get(node).add(next);
            map.get(next).add(node);
        }
        
         int count =0;//연결 지점의 수

         for(int i=1; i<=N; i++){

             if(node[i] ==0){
                 count ++;
                 bfs(i);
             }

         }
        System.out.println(count);


    }
}