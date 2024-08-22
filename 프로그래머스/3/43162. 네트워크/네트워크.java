import java.util.*;
class Solution {
    private static void bfs(int start ,int[][] computers, boolean[] vis){
        Queue<Integer> q= new LinkedList<>();
        q.add(start);
        vis[start] = true;
        
        while(!q.isEmpty()){
            int cur = q.poll();
            
            for(int i=0; i<computers.length; i++){
                if(computers[cur][i] ==1 &&!vis[i]){
                    q.add(i);
                    vis[i] =true;
                }
            }
        }
        
        
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        boolean[] vis = new boolean[n];
        
        for(int i=0; i<n; i++){//노드탐색
            if(!vis[i]){
                answer++;
                bfs(i, computers,vis);
                    
            }
        }
        return answer;
    }
}