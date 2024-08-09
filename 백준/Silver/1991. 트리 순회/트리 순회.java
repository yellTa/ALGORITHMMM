import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int n =0;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int [] lc = new int[40];
    static int [] rc = new int[40];

    private static void preorder(int cur){
        System.out.print((char)(cur+'A'-1));
        if(lc[cur] !=0) preorder(lc[cur]);
        if(rc[cur] !=0) preorder(rc[cur]);
    }


    private static void inorder(int cur){

        if(lc[cur] !=0) inorder(lc[cur]);
        System.out.print((char)(cur+'A'-1));
        if(rc[cur] !=0) inorder(rc[cur]);
    }


    private static void postorder(int cur){

        if(lc[cur] !=0) postorder(lc[cur]);
        if(rc[cur] !=0) postorder(rc[cur]);
        System.out.print((char)(cur+'A'-1));
    }

    public static void main(String[] args) throws IOException{


        n = Integer.parseInt(br.readLine());

        for(int i=1; i<=n; i++){//부모노드를 인덱스로 쓸 에정임 노드 A =1로 0으로쓰니까 노드에 값이 없는 경우에서 걸림
            //아니면 초기값을 -1로 두던가 근데 그러면 연산이 추가되니까 걍 1을 시작점으로 둔다.
            String l,r,c;
            st = new StringTokenizer(br.readLine());

            c = st.nextToken();
            l= st.nextToken();
            r= st.nextToken();

            if(!l.equals(".")) lc[c.charAt(0) -'A'+1] = l.charAt(0) -'A'+1;
            if(!r.equals(".")) rc[c.charAt(0)- 'A'+1] = r.charAt(0)-'A'+1;
        }

        preorder(1);
        System.out.println();
        inorder(1);
        System.out.println();
        postorder(1);
        System.out.println();

    }

}