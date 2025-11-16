class Solution {
    public static int firstUniqChar(String s) {
        int[][] p = new int[26][2];
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            p[c][0] = p[c][0] + 1;
            p[c][1] = i;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < p.length; i++) {
            if (p[i][0] == 1) {
                ans = Math.min(p[i][1], ans);
            }
        }
             return ans==Integer.MAX_VALUE?-1:ans;

    }
}