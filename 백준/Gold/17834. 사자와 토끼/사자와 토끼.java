// 이분그래프는 그래프의 노드를 두개의 집합으로 나눌 수 있음 
// ->서로 다른 집합의 노드끼리만 연결 됨 ex/ 집합 1, 집합1 은 연결 안됨. 집합 1- 집합 2 가 연결됨

// 이걸 이용하면. . .

//사자와 토끼가 이분 그래프의 서로 다른 집합에 속해 있으면
//계속해서 이동할때 계속 서로 다른 집합으로 이동하게  됨으로
//절대 만나지 않음을 알 수 있음.

//즉, 사자와 토끼가 초기에 서로 다른 이분그래프의 두 집합에 각각 존재하면,
// 서로 만나지 않음  -> 요걸 이해하고 시작해야함.




import java.util.*;

public class Main {

    // 최대 노드 수
    private static final int MAX_NODES = 50001;
    // 각 노드의 인접 리스트를 저장할 배열
    private static List<Integer>[] adj = new ArrayList[MAX_NODES];
    // 각 노드의 집합 정보를 저장할 배열 (0은 미방문, 1과 2는 두 집합)
    private static int[] group = new int[MAX_NODES];
    
    // BFS를 사용하여 그래프가 이분 그래프인지 확인하고, 집합을 나누는 함수
    private static boolean bfs(int start) {
        // 노드와 해당 노드의 집합 정보를 저장할 큐
        Queue<Map.Entry<Integer, Integer>> queue = new LinkedList<>();
        queue.add(new AbstractMap.SimpleEntry<>(start, 1)); // 시작 노드와 집합 1
        
        // 시작 노드에 집합 1 할당
        group[start] = 1;
        
        // 큐가 비어있지 않을 동안 계속 탐색
        while (!queue.isEmpty()) {
            // 큐에서 현재 노드와 집합 정보를 꺼냄
            Map.Entry<Integer, Integer> current = queue.poll();
            int cur = current.getKey();
            int currentGroup = current.getValue();
            
            // 현재 노드의 모든 인접 노드에 대해 처리
            for (int next : adj[cur]) {
                if (group[next] == 0) {
                    // 인접 노드가 아직 방문되지 않은 경우, 다른 집합으로 나누기
                    int nextGroup = (currentGroup == 1) ? 2 : 1;
                    group[next] = nextGroup;
                    queue.add(new AbstractMap.SimpleEntry<>(next, nextGroup));
                } else if (group[next] == currentGroup) {
                    // 인접 노드가 현재 노드와 같은 집합에 있으면 이분 그래프가 아님
                    return false;
                }
            }
        }
        return true; // 그래프가 이분 그래프인 경우
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); // 수풀(노드) 수
        int e = sc.nextInt(); // 오솔길(엣지) 수
        
        // 인접 리스트 초기화
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        // 엣지 정보 입력
        for (int i = 0; i < e; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        
        boolean isBipartite = true; // 그래프가 이분 그래프인지 여부를 나타내는 변수
        for (int i = 1; i <= n; i++) {
            if (group[i] == 0) { // 아직 집합이 지정되지 않은 노드에 대해
                isBipartite = bfs(i); // BFS를 사용하여 이분 그래프인지 확인
                if (!isBipartite) { // 이분 그래프가 아닌 경우
                    break;
                }
            }
        }
        
        if (isBipartite) {
            long cnt1 = 0; // 집합 1의 노드 수
            long cnt2 = 0; // 집합 2의 노드 수
            for (int i = 1; i <= n; i++) {
                if (group[i] == 1) {
                    cnt1++;
                } else if (group[i] == 2) {
                    cnt2++;
                }
            }
            long result = cnt1 * cnt2 * 2; // 집합 1의 노드 수 * 집합 2의 노드 수 * 2
            System.out.println(result); 
        } else {
            System.out.println(0); // 이분 그래프가 아닌 경우 0 출력
        }
        
        sc.close();
    }
}
