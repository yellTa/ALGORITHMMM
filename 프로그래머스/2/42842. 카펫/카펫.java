import java.util.*;
import java.io.*;

/*
[IDEA]
W = brown + yellow (넓이)
2차원 배열A에 경우의 수 담기
담는 조건 - [a,b] a>=b;인 경우에만 담는다.[가로,세로]

for(A의 수 만큼 )
A의 (가로 -2)*(세로-2) == yello -> [가로,세로] 리턴

--- n2으로 10^12나와서 시간초과 나오는 방법

가로-2 * 세로-2 == yellow의 값이다.

가로세로의 경우의 수를 고르는 것이 아니라
가로 세로를 탐색하는 방안은?

w>=3
h>=3

w의 길이의 최대 = brown+yellow(세로1 가로 n인 경우)

w<=n만큼

for(int w=1; w<=n; w++){
    h = n/w;
    if(n%w ==0) //가로 세로는 n의 약수여야 함
    if(h>=3 && w>=h) 가로가 세로보다 길고h>=3이상인경우
    if(h-2 * w-2==yellow)
    w,h리턴하기
}


 */
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        int n = brown+yellow;
        for(int w=3; w<=n; w++){
            int h = n/w;
            
            if(n%w ==0){
                if(h>=3 && w>=h){
                    if((h-2)*(w-2) == yellow){
                        answer[0] = w;
                        answer[1] =h;
                        return answer;
                    }
                }
            }
        }
        
     

        return answer;
    }
}