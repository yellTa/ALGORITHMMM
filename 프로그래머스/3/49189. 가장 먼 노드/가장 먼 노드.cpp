#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
   int answer=0;
    
    vector<vector<int>> graph(n+1);
    
    for(int i=0; i< edge.size(); i++){
        int from = edge[i][0];
        int to = edge[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    //방문한 곳
    vector<int> dist(n+1, -1); // n+1사이즈 초기화 -1로 채우기
    queue<int> q;
    
    //시작점
    dist[1] =0;
    q.push(1);
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for(int next : graph[current])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    
    
    int far = *max_element(dist.begin(), dist.end());
    
    for(int i=0; i<dist.size(); i++)
    {
        if(dist[i] == far)
        {
            answer++;
        }
    }
    
    
    return answer;
}
