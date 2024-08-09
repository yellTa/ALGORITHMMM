class Solution {
    public int solution(String name) {
        int answer = 0;
        
        int len = name.length();
        int move = len - 1;
        
        for (int i = 0; i < len; i++) {
            answer += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);
            int pA = i + 1;
            while (pA < len && name.charAt(pA) == 'A') {
                pA++;
            }
            move = Math.min(move, i * 2 + len - pA);
            move = Math.min(move, (len - pA) * 2 + i);
        }
        return answer + move;
    }
}
