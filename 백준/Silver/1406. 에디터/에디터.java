

import java.io.*;
import java.util.*;

public class Main {


    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        LinkedList<Character> list = new LinkedList<Character>();
        for(int i=0; i<s.length(); i++){
            list.add(s.charAt(i));
        }


        int tc = Integer.parseInt(br.readLine());

        ListIterator<Character> iter = list.listIterator();
        
        while(iter.hasNext()){// iterator를 이용해서 마지막 커서 위치로 이동시킨다.
            iter.next();
        }

        while(tc-- != 0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if(command.equals("L")){
                if(iter.hasPrevious()) iter.previous(); //왼쪽으로 이동

            }else if(command.equals("D")){
                if(iter.hasNext()) iter.next();//오른쪽으로 이동

            }else if(command.equals("B")){
                if(iter.hasPrevious()){
                    iter.previous(); //왼쪽으로 이동
                    iter.remove(); //remove는 previous나 next로 반환된 가장 마지막 요소를 제거한다.
                    //즉 remove하기 전에 iter을 움직여줘고 바로 삭제해야 원하는 값을 지운다는 뜻
                }
            }else if(command.equals("P")){
                char word = st.nextToken().charAt(0);
                iter.add(word);
            }

        }

        for(char c : list){
            bw.write(Character.toString(c)) ;
        }

        bw.flush();;
        bw.close();
    }
}
