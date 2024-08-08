import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;

    private static int w, h, answer;
    private static int[][] map, visited;

    private static Queue<Pos> q = new LinkedList<>();
    private static int[] dy = {-1, -1, 0, 1, 1, 0};
    private static int[][] dx = {
            {0, 1, 1, 1, 0, -1},
            {-1, 0, 1, 0, -1, -1}
    };

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        visited = new int[h][w];
        map = new int[h][w];
        for (int y = 0; y < h; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < w; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (visited[y][x] == 1) {
                    continue;
                }

                var home = map[y][x];
                var in = true;
                var borderTotal = 0;

                q.add(new Pos(y, x));
                visited[y][x] = 1;

                while (!q.isEmpty()) {
                    Pos cur = q.poll();

                    var border = 6;
                    for (int dir = 0; dir < 6; dir++) {
                        var ny = cur.y + dy[dir];
                        var nx = cur.x + dx[cur.y % 2][dir];

                        if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                            in = false;
                            continue;
                        }
                        if (map[ny][nx] != home) {
                            continue;
                        }
                        if (visited[ny][nx] == 1) {
                            border--;
                            continue;
                        }

                        q.add(new Pos(ny, nx));
                        visited[ny][nx] = 1;
                        border --;
                    }
                    borderTotal += border;
                }

                if (home == 0 && in) {
                    answer -= borderTotal;
                    continue;
                }

                if (home == 1) {
                    answer += borderTotal;
                }
            }
        }

        System.out.println(answer);
    }

    private static class Pos {
        private int y;
        private int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}