import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();

        // 오늘 날짜를 계산하여 변수에 저장
        int checkDate = getDate(today);

        // 날짜를 계산하기 위해 약관 종류와 기간을 맵에 저장
        for (String s : terms) {
            String[] term = s.split(" ");
            map.put(term[0], Integer.parseInt(term[1]));
        }

        // 개인정보 배열 privacies를 순회하며 처리 완료된 개인정보의 인덱스를 찾아서 리스트에 추가
        for (int i = 0; i < privacies.length; i++) {
            String[] privacy = privacies[i].split(" ");

            // 처리 완료일 계산(개인정보 처리 시작일 + 처리 기간 * 28일)
            if (getDate(privacy[0]) + (map.get(privacy[1]) * 28) <= checkDate) {
                answer.add(i + 1);
            }
        }

        // 리스트를 배열로 변환하여 반환
        return answer.stream().mapToInt(i -> i).toArray();
    }

    // 날짜를 입력받아 계산하여 정수값으로 반환하는 메서드
    public static int getDate(String date) {
        String[] arr = date.split("\\.");

        int year = Integer.parseInt(arr[0]);
        int month = Integer.parseInt(arr[1]);
        int day = Integer.parseInt(arr[2]);

        // 날짜를 연도 * 12 * 28 + 월 * 28 + 일 로 계산하여 반환
        return (year * 12 * 28) + (month * 28) + day;
    }
}