import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int[] isused = new int [10000000];
    static int[] result = new int [10000000];
    private static void dfs(ArrayList<ArrayList<Integer>> list){
        Stack<Integer>  st = new Stack<>();

        //초기화
        st.push(1);

        int cnt =0;
        while(!st.isEmpty()){
            int cur = st.pop();
            //현재 노드와 연결된 노드 탐색
            for(int next : list.get(cur)){
                if(isused[next]==0){//계속 탐색
                    isused[next] =1;
                    result[next] = cur; //부모를 기록
                    st.push(next);//다음 기록
                }
            }

        }

    }

    public static void main(String[] args) throws IOException {
        //정보 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        ArrayList<ArrayList<Integer>>  list = new ArrayList<>();

        //arrayList배열 초기화
        for(int i=0; i<=N; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            list.add(arr);
        }

        StringTokenizer st;
        for(int i=1; i<N; i++){
             st = new StringTokenizer(br.readLine());

            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            list.get(l).add(r);
            list.get(r).add(l);

        }

//        for(int i=1; i<=N; i++){
//            System.out.println(list.get(i).toString());
//        }

        dfs(list);

        for(int i=2; i<=N; i++){
            System.out.println(result[i]);
        }
    }
}