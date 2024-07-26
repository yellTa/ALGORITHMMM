import java.util.*;

class Solution {
    public List<?> solution(String[] genres, int[] p) {
        List<Integer> answer = new ArrayList<>();
        //1. 장르별 노래 수 비교
        //Map의 네 가지 종류
        //LinkedHashMap , ConcurrentHashMap, TreeMap(key value 자동정렬), HashMap
        
        Map<String, Integer> genPlayStore = new HashMap<>();
        
        //1.A 쌍맵 만들기
        for(int i=0; i< genres.length; i++){
            if(genPlayStore.containsKey(genres[i])){
                int x = genPlayStore.get(genres[i]);
                genPlayStore.put(genres[i], x+p[i]);
            }else genPlayStore.put(genres[i], p[i]);
        }
        //1.B play기준으로 정렬하기
        List<Map.Entry<String,Integer>> entryList = new LinkedList<>(genPlayStore.entrySet());
        
        entryList.sort((o1,o2) -> o2.getValue().compareTo(o1.getValue()));
        
        // for(Map.Entry<String, Integer> map : entryList){
        //     System.out.print(map.getKey());
        //     System.out.println("  : "+map.getValue());
        // }
        
        //2. 장르별 가장 많은 들은 애들 2개씩 봅아서 넣기 - 1개인 애들은 1개만 넣는다
        //장르별로 순회하면 된다.
    
        //2.A.1 idx : plays 맵을 만들어버리기 plays가 큰 순으로 정렬
        for(Map.Entry<String ,Integer> map : entryList){
            String genre = map.getKey();// 순회할 장르가 나온다.
            Map<Integer, Integer> idxPlays = new HashMap<>();
            
            for(int i=0; i< p.length;i++){
                if(genres[i].equals(genre)){
                    idxPlays.put(i, p[i]);
                }    
            }
            List<Map.Entry<Integer, Integer>> idxPlayList = new LinkedList<>(idxPlays.entrySet());
            idxPlayList.sort((o1,o2) -> o2.getValue().compareTo(o1.getValue()));
            
            //2개만 뽑고 stop하기
            int count=0;
            for(Map.Entry<Integer, Integer> idxMap: idxPlayList){
                count ++;
                answer.add(idxMap.getKey());
                if(count ==2) break;
            }
        }
      
        return answer;
    }
}