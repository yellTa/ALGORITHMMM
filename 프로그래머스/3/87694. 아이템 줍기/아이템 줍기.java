import java.util.*;

class Solution {
    static int[][] board;
    static int[] dx = {1, -1, 0, 0}; // 상하좌우
    static int[] dy = {0, 0, 1, -1}; // 상하좌우
    static boolean[][] visited;
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        // board 크기는 101x101로 충분히 크게 설정
        board = new int[101][101];
        visited = new boolean[101][101];
        
        // 2배 확대하여 좌표를 더 정확하게 관리
        for (int[] rec : rectangle) {
            int x1 = rec[0] * 2;
            int y1 = rec[1] * 2;
            int x2 = rec[2] * 2;
            int y2 = rec[3] * 2;
            
            // 사각형 경계선만 그리기
            for (int i = x1; i <= x2; i++) {
                board[i][y1] = 1; // 상단 경계
                board[i][y2] = 1; // 하단 경계
            }
            for (int i = y1; i <= y2; i++) {
                board[x1][i] = 1; // 좌측 경계
                board[x2][i] = 1; // 우측 경계
            }
        }
        
        // 내부 채우기 방지: 경계 내부의 좌표를 0으로 유지
        for (int[] rec : rectangle) {
            int x1 = rec[0] * 2;
            int y1 = rec[1] * 2;
            int x2 = rec[2] * 2;
            int y2 = rec[3] * 2;
            
            for (int i = x1 + 1; i < x2; i++) {
                for (int j = y1 + 1; j < y2; j++) {
                    board[i][j] = 0; // 내부 비우기
                }
            }
        }

        // BFS를 통해 최단 거리 계산
        return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    }

    private int bfs(int startX, int startY, int targetX, int targetY) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] {startX, startY, 0});
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];
            int dist = current[2];
            
            // 목적지에 도달하면 거리 반환
            if (x == targetX && y == targetY) {
                return dist / 2; // 2배 확대했으므로 거리도 2로 나눠서 반환
            }
            
            // 상하좌우로 이동
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 범위 안에 있고, 경계선이며 방문하지 않은 경우에 이동
                if (nx >= 0 && ny >= 0 && nx < 101 && ny < 101 && board[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    queue.add(new int[] {nx, ny, dist + 1});
                }
            }
        }
        return -1; // 도달할 수 없는 경우 (이 문제에서는 발생하지 않음)
    }
}
