
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        int[] store = new int[tc];

        int sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < store.length; i++) {
            int x = Integer.parseInt(br.readLine());
            map.put(x, map.getOrDefault(x, 0) + 1);
            sum += x;
            store[i] = x;
        }
        //산술 평균
        int avg = (int) Math.round((double) sum / store.length);
        System.out.println(avg);

        //중앙값
        Arrays.sort(store);
        System.out.println(store[store.length / 2]);

        //최빈값
        ArrayList<int[]> arr = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int[] temp = new int[]{
                    entry.getKey(), entry.getValue()};

            arr.add(temp);
        }

        Collections.sort(arr, (a, b) -> {
            int cmp = b[1] - a[1];
            if (cmp == 0) {
                return a[0] - b[0];
            }
            return cmp;
        });


        if (arr.size() >=2 &&arr.get(0)[1] == arr.get(1)[1]) {
            System.out.println(arr.get(1)[0]);
        }else System.out.println(arr.get(0)[0]);


        //범위
        System.out.println(store[store.length - 1] - store[0]);

    }
}
