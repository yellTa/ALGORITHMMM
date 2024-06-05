import java.util.*;
import java.io.*;
/*
[IDEA]
정렬한 후 가장 작은 것과 가장 큰것을 더한다. -> 위의 경우가 무게를 최대로 채워서 갈 수 있는 경우
적은 인원으로 왜냐? 인원 수는 2인이 끝이니까

조건 무인도에 갇힌 사람은 1이상 50000이하 -> 1명인 경우는 1번만 가면 됨

[필요한 것]
index i, pointer j  // j는 끝부분의 인덱스임
limit -> limit수
answer -> count를 저장;

*/
class Solution {
    public int solution(int[] p, int limit) {
        int answer = 0;
    
        if(p.length ==1)return 1;
            
        Arrays.sort(p);
        
        int j = p.length-1;
        int i=0;
        
        while(true){
            
             if(p[i] + p[j] > limit){
                answer ++;
                j--;
                 
                if(j==0|| j==i)return answer +1;
                continue;
            }
            
             if(p[i] + p[j]<=limit){
                if(i==j || j-i==1|| j==0)return answer+1;
                i++; j--;
                answer++;
            }
            
        }
        
    }
}
