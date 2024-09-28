import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc= Integer.parseInt(br.readLine());

        StringTokenizer st;

        Body[] store = new Body[tc];
        int idx=0;
        int[] rank = new int[tc];
        while(tc-- >0){
            st = new StringTokenizer(br.readLine());
            int tall = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            Body body = new Body(tall,weight,0);
            store[idx++] = body;
        }



        for(int i=0; i< store.length; i++){
            int count=1;

            for(int k=0; k<store.length; k++){
                if(i==k)continue;
                if(store[i].tall< store[k].tall && store[i].weight<store[k].weight){
                    count++;
                }
            }
            rank[i]=count;
        }

        for(int k: rank){
            System.out.print(k + " ");
        }

    }


    static class Body{
        int tall;
        int weight;
        int sequence;

        public Body(int tall, int weight, int sequence){
            this.tall = tall;
            this. weight = weight;
            this.sequence = sequence;
        }
    }
}