import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static boolean[] visited; // 방문 체크 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); // 총 사람 수
        int V = Integer.parseInt(br.readLine()); // 친구 관계 수

        int[][] adjMatrix = new int[N + 1][N + 1]; // 인접 행렬
        visited = new boolean[N + 1]; // 방문 배열

        // 친구 관계 입력
        for (int i = 0; i < V; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1; // 무방향 그래프이므로 대칭으로 설정
        }

        System.out.println(bfs(1, adjMatrix)); // BFS로 탐색하고 초대할 친구 수 출력
    }

    private static int bfs(int start, int[][] adjMatrix) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true; // 상근이(1번) 방문 처리

        int level = 0; // 현재 깊이 (1단계, 2단계를 나누기 위한 변수)
        int count = 0; // 초대할 친구 수

        // BFS 시작
        while (!queue.isEmpty() && level < 2) { // 2단계까지만 탐색
            int size = queue.size(); // 현재 레벨에서 탐색할 사람 수
            level++;

            // 현재 레벨에서의 모든 친구를 탐색
            for (int i = 0; i < size; i++) {
                int current = queue.poll();

                // 현재 사람의 모든 친구 탐색
                for (int j = 1; j < adjMatrix.length; j++) {
                    if (adjMatrix[current][j] == 1 && !visited[j]) {
                        visited[j] = true; // 친구 방문 처리
                        queue.add(j); // 친구의 친구를 큐에 추가
                        count++; // 초대할 친구 수 증가
                    }
                }
            }
        }
        return count; // 초대할 친구 수 반환
    }
}
