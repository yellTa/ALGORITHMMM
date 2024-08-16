
import java.io.*;
import java.util.*;

public class Main {


    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();


        int tc = Integer.parseInt(br.readLine());

        Stack<Character> left = new Stack<>();
        Stack<Character> right = new Stack<>();

        //값 세팅하기
        for(int i=0 ;i< s.length(); i++){
            left.push(s.charAt(i));
        }

        while(tc-- != 0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if(command.equals("L")){
                //왼쪽으로 이동
                // 왼쪽에서 빼서 오른쪽으로 넣어주기
                if(!left.isEmpty()){
                    right.push(left.pop());
                }

            }else if(command.equals("D")){
                //오른쪽으로 이동
                //오른쪽에서 빼서 왼쪽에 넣어주기
                if(!right.isEmpty()){
                    left.push(right.pop());
                }

            }else if(command.equals("B")){

                //왼쪽 문자 삭제하기
                if(!left.isEmpty())left.pop();

            }else if(command.equals("P")){
                //삽입 - 왼쪽에 넣으면 된다.
                char word = st.nextToken().charAt(0);
                left.push(word);
            }

        }
        //왼쪽에 있는 값을 모두 오른쪽에 옮긴 다음에 출력하면 됨
        StringBuilder sb = new StringBuilder();

        while(!left.isEmpty())
            right.push(left.pop());

        while(!right.isEmpty())
            bw.write(right.pop());

        bw.flush();
        bw.close();
    }
}
