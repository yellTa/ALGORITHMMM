import java.util.*;

class Solution {
    static int[][] board;
    static int[] dx = {1, -1, 0, 0}; // 상하좌우
    static int[] dy = {0, 0, 1, -1}; // 상하좌우
    static boolean[][] visited;
    
    
    private static int bfs(int startX, int startY, int itemX, int itemY){
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{startX, startY,0});
        visited[startX][startY] =true;
        
        while(!queue.isEmpty()){
            int[] cur =queue.poll();
            int x = cur[0];
            int y = cur[1];
            int dist = cur[2];
            
            for(int dir =0; dir<4; dir++){
                int nx = x  + dx[dir];
                int ny = y +dy[dir];
                
                if(nx<0 || ny <0 || nx>=101|| ny>=101)continue;
                if(itemX==x && y ==itemY){
                    return (dist+1)/2;
                }
                if(board[nx][ny] ==1 && !visited[nx][ny]){
                    visited[nx][ny] =true;
                    queue.add(new int[]{nx,ny,dist+1});
                }
            }
            
        }
       return -1;
    }
    
    
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        // board 크기는 101x101로 충분히 크게 설정
        board = new int[101][101];
        visited = new boolean[101][101];
        
        // 2배 확대하여 좌표를 더 정확하게 관리
        for (int[] rec : rectangle) {
            int x1 = rec[0]*2;
            int y1 = rec[1]*2;
            int x2 = rec[2]*2;
            int y2 = rec[3]*2;
           //x축 채우기

//             //테두리만 입력하는 방법
            //x기준 먼저 채우기
                for(int x = x1; x<=x2; x++){
                    board[x][y1] = 1;
                    board[x][y2]=1;
                }
            //y기준 테두리 표시하기
                for (int y = y1; y <= y2; y++) {
                    board[x1][y] = 1; // 좌측 경계
                    board[x2][y] = 1; // 우측 경계
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

}
