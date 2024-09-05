import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.*;

class Main {
    static int[] vis;

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int node = Integer.parseInt(st.nextToken());
        int line = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());

        vis = new int[node+1];

        ArrayList<ArrayList<Integer>> templist = new ArrayList<>();

        for(int i=0; i< node+1; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            templist.add(arr);
        }

        //값 받기

        for(int i=0; i<line; i++){
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            templist.get(x).add(y);
            templist.get(y).add(x);
        }

        //정렬하기
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for(int i=0; i<templist.size(); i++){
            ArrayList<Integer>arr = new ArrayList<>();
            arr = templist.get(i);
            Collections.sort(arr);
            list.add(arr);
        }

        //dfs를 통해서 돌리기
        ArrayList<Integer> answer = new ArrayList<>();
        dfs(start, list, answer);

        for(int x : answer){
            System.out.print(x + " ");
        }
        System.out.println();


        for(int i=0; i<node +1; i++){
            vis[i] =0;
        }

        answer = new ArrayList<>();

        bfs(start,list, answer );

        for(int x : answer){
            System.out.print(x + " ");
        }
        System.out.println();
    }
    private static ArrayList<Integer> dfs(int start, ArrayList<ArrayList<Integer>> list, ArrayList<Integer> answer){
        vis[start] =1;
        answer.add(start);

        for(int x: list.get(start)){
            if(vis[x]==0){
                dfs(x,list,answer);
            }

        }
        return answer;
    }

    private static ArrayList<Integer> bfs(int start, ArrayList<ArrayList<Integer>> list, ArrayList<Integer> answer){
        vis[start]=1;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        answer.add(start);

        while(!q.isEmpty()){
            int cur = q.poll();//list.get(cur) 해서 노드들 다 탐색할꺼임
            vis[cur] =1;


            for(int x : list.get(cur)){
                if(vis[x] ==0){
                    q.add(x);
                    vis[x] =1;
                    answer.add(x);
                }
            }
        }

        return answer;
    }


}