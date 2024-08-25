import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution {
    private static boolean[] visited; // 방문한지 안한지를 체크하는 visited 배열
    private static List<String> result = new ArrayList<>();

    public static String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        
        dfs(0, "ICN", "ICN", tickets);
        Collections.sort(result);
        
        String[] answer = result.get(0).split(" ");
        return answer;
    }

    public static void dfs(int idx, String start, String route, String[][] tickets) {
        if (idx == tickets.length) {
            result.add(route);
            return;
        }

        for (int i = 0; i < tickets.length; i++) {
            if (tickets[i][0].equals(start) && !visited[i]) {
                visited[i] = true;
                dfs(idx + 1, tickets[i][1], route + " " + tickets[i][1], tickets);
                visited[i] = false;
            }
        }
        return;
    }
}