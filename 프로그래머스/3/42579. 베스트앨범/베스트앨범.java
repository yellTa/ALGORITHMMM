import java.util.*;
import java.io.*;
/*
[문제]
1. 속한 노래가 많이 재생된 장르
2. 장르 내에서 많이 재생된 노래 수
3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유번호가 낮은 노래 먼저 수록

[출력]
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return

[제약]
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.

장르 별로 가장 많이 재생된 노래를 최대 두 개까지 모아 베스트 앨범을 출시하므로 2번 노래는 수록되지 않습니다.


[Idea]
1. 장르 많이 순으로 정렬
2. 장르에서 음악 많이 들은거 2개 뽑기
3. 뽑은 음악의 인덱스 저장하기 
4. 위의 작업을 장르 갯수만큼 반복하기

1. 장르많이 순으로 정렬

map<string, int> 장르 : 횟수
map을 int 순으로 정렬 map.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));

정렬된 map의 장르 순대로 for문 돌림-> 장르 갯수만큼 반복하는 거니까

2. 장르에서 음악 많이 들은거 2개 뽑기

장르에 해당하는 음악들 뽑아내서 배열에 넣기
배열에 넣은 애들 정렬하기(오름차순) 
맨 뒤에 두 개 값에 해당하는 인덱스 찾기 -> 처음에 음악의 횟수와 인덱스의 위치가 짝인 map만들기
ex ) music<int,int(횟수, 인덱스)> 여기는 모든 음악이 다 들어가 있음
음악의 수를 key로 사용해서 인덱스 뽑아내서 배열에 저장(배열 사이즈 =  장르*2)


[psudo code]
1. map<String ,int>장르가 키, int는 장르 나온 횟수
2. music map<int,int> 음악과 인덱스 넣기
3. map을 int기준으로 정렬하기
4. map에서 뽑아낸 장르 수 만큼 반복하기 - loop
5. 장르에서 음악 많이 들은거 2개 뽑기 시작
    장르에 해당하는 음악 뽑아서 배열에 넣고 정렬하기
    배열에서 젤 큰수 그 다음 수 musicMap에서 찾기
    찾은 값 정답 인덱스에 넣기

*/

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        //1. map<String ,int>장르가 키, int는 장르 나온 횟수
        //2. music map<int,int> 음악과 인덱스 넣기
        
        Map<String, Integer> map  = new HashMap<>();
        Map<Integer,Integer> musicMap = new HashMap<>();
        
        for(int i=0; i<plays.length; i++){
            musicMap.put(plays[i], i);
        }
        
        for(int i=0; i<genres.length; i++){
            String s = genres[i];
            map.put(s, map.getOrDefault(s,0) +plays[i]);
        }
        
          
        //map을 int 기준으로 정렬하기
         List<String> keySet = new ArrayList<>(map.keySet());   
         keySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));
        
        //musicMap 오름차순 정렬하기 인덱스 값 기준으로
         List<String> mkeySet = new ArrayList<>(map.keySet());   
         mkeySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));
        
        //map에서 뽑아낸 장르수 만큼 반복하기
        
        for(String s : keySet){
            //음악 많이 들은거 뽑기 시작
            List<Integer> A = new ArrayList<>();
            
            for(int i=0; i<genres.length; i++){
                if(genres[i].equals(s)){
                    A.add(plays[i]);
                }
            }
            //정렬하고 젤 큰수 두개 찾기
            Collections.sort(A);
            
            if(A.size()>=2){
                int max = A.get(A.size()-1);
                int nmax = A.get(A.size()-2);
                if(max ==nmax){
                    int count =0;
                    for(int i=0; i<plays.length; i++){
                        if(plays[i] == max){
                            count++;
                            answer.add(i);
                        }
                        if(count ==2)break;
                    }
                    
                }else{
                    answer.add(musicMap.get(max)); 
                    answer.add(musicMap.get(nmax));    
                }
                
            }else if(A.size()==1){
                System.out.println(A.get(0));
                answer.add(musicMap.get(A.get(0)));
            } 
        }
        
        return answer;
    }
}