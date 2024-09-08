import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine()); // 테스트 케이스 수

        while (tc-- > 0) {
            String func = br.readLine(); // 함수 명령어
            int len = Integer.parseInt(br.readLine()); // 배열 길이
            String arr = br.readLine(); // 배열

            // 배열을 Deque로 변환
            Deque<String> deque = change(arr);

            boolean isReversed = false; // 방향을 나타내는 플래그
            boolean isError = false; // 에러 상태

            for (char command : func.toCharArray()) {
                if (command == 'R') {
                    // R이 나오면 방향을 반전
                    isReversed = !isReversed;
                } else if (command == 'D') {
                    if (deque.isEmpty()) {
                        // 배열이 비어있으면 에러
                        isError = true;
                        break;
                    }

                    // 방향에 따라 앞에서 제거할지 뒤에서 제거할지 결정
                    if (isReversed) {
                        deque.removeLast();
                    } else {
                        deque.removeFirst();
                    }
                }
            }

            // 결과 출력
            if (isError) {
                System.out.println("error");
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append("[");

                while (!deque.isEmpty()) {
                    if (isReversed) {
                        sb.append(deque.removeLast());
                    } else {
                        sb.append(deque.removeFirst());
                    }
                    if (!deque.isEmpty()) {
                        sb.append(",");
                    }
                }

                sb.append("]");
                System.out.println(sb);
            }
        }
    }

    private static Deque<String> change(String arr) {
        Deque<String> deque = new ArrayDeque<>();
        // 입력이 빈 배열이면 빈 deque 반환
        if (arr.equals("[]")) {
            return deque;
        }

        // 배열에서 대괄호 제거하고 요소 추가
        String s = arr.substring(1, arr.length() - 1);
        String[] elements = s.split(",");

        for (String element : elements) {
            deque.add(element);
        }

        return deque;
    }
}
