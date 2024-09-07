import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numbers = Integer.parseInt(br.readLine());

        int[] store = new int[1000010];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < numbers; i++) {
            int value = Integer.parseInt(st.nextToken());
            store[value] = 1;
        }

        int target = Integer.parseInt(br.readLine());
        int answer = 0;

        // i는 target/2까지만 확인하면 됩니다.
        for (int i = 1; i <= target / 2; i++) {
            if (store[i] == 1 && target - i <= 1000000 && target - i > 0 && store[target - i] == 1 && i != target - i) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}
