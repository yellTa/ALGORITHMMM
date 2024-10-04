import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// 12개의 줄에 필드의 정보가 주어짐
//각 줄에는 6개의 문자가 있다.
//뿌요뿌요들은 아래로 떨어진 상태(즉 아래쪽에 있는 것임)


class Main {

    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    static char map[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        map = new char[12][6];

        //뿌요 받기
        for (int i = 0; i < 12; i++) {
            String s = br.readLine();
            for (int k = 0; k < 6; k++) {
                map[i][k] = s.charAt(k);
            }
        }
        int count = 0;

        while (true) {
            if (deletePuyo() == false) {

                break;
            } else {
                count++;
            }
            downPuyo();
            //뿌요 내리기
//            for (int i = 0; i < 12; i++) {
//                for (int k = 0; k < 6; k++) {
//                    System.out.print(map[i][k] + " ");
//
//                }
//                System.out.println();
//            }
//            System.out.println(count);
//            System.out.println();
        }
        System.out.println(count);

    }

    private static void downPuyo() {
        for (int i = 0; i < 6; i++) {
            Queue<Puyo> q = new LinkedList<>();
            for (int k = 11; k >= 0; k--) {
                if (map[k][i] != '.') {
                    q.add(new Puyo(k, i, map[k][i]));
                    map[k][i]='.';
                }
            }

            int idx = 11;
            while(!q.isEmpty()){
                map[idx--][i] = q.poll().color;
            }

        }


    }


    private static boolean deletePuyo() {//제거할 뿌요가 없으면 false리턴
        boolean result = false;

        for (int i = 0; i < 12; i++) {
            for (int k = 0; k < 6; k++) {
                if (!(map[i][k] == '.')) {
                    List<Puyo> puyos = new ArrayList<>();
                    //bfs 시작
                    if (bfs(i, k, puyos)) {//뿌요를 제거해야하는 경우
                        result = true;
                    }
                }
            }
        }

        return result;
    }

    private static boolean bfs(int i, int k, List<Puyo> puyos) {
        int vis[][] = new int[12][6];

        Queue<Puyo> q = new LinkedList<>();
        //시작 초기화
        Puyo puyo = new Puyo(i, k, map[i][k]);
        puyos.add(puyo);
        q.add(puyo);
        vis[i][k] = 1;

        while (!q.isEmpty()) {
            Puyo cur = q.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) {
                    continue;
                }
                if (vis[nx][ny] == 0 && map[nx][ny] == (cur.color)) {
                    Puyo temp = new Puyo(nx, ny, cur.color);
                    q.add(temp);
                    puyos.add(temp);
                    vis[nx][ny] = 1;
                }
            }
        }
        //뿌요를 삭제해야하면 true설정
        if (puyos.size() >= 4) {

            //뿌요 삭제하기
            for (Puyo temp : puyos) {
                map[temp.x][temp.y] = '.';
            }
            return true;
        }

        return false;
    }


    static class Puyo {
        int x;
        int y;
        char color;


        public Puyo(int x, int y, char color) {
            this.x = x;
            this.y = y;
            this.color = color;
        }
    }

}