class Solution {
     public String solution(String[] cards1, String[] cards2, String[] goal) {
        int c1=0; int c2=0;

        for (String s : goal) {
          //1. 첫번째 카드뭉치에서 찾기 있으면 continue;
          if (c1 < cards1.length && s.equals(cards1[c1])) {
            c1++;
            continue;
          }
          //2. 두 번쨰 카드 뭉치에서 찾기 있으면 continue;
          if (c2 < cards2.length && s.equals(cards2[c2])) {
            c2++;
            continue;
          }
          //3. 둘 다 없는 경우

          return "No";
        }

        return "Yes";
    }
}