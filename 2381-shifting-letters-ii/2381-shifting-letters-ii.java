class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] diff = new int[n];
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int inc = shift[2] == 0 ? -1 : 1;
            diff[start] += inc;
            if (end + 1 < n)
                diff[end + 1] -= inc;
        }
        for (int i = 0; i < n; i++) {
            if (i == 0)
                continue;
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            diff[i] = diff[i] % 26;
        }
        String ans = "";
        for (int i = 0; i < n; i++) {
            int inc = (s.charAt(i) - 'a' + diff[i]) % 26;
            if (inc < 0)
                inc+=26;
            char c = (char) ('a' + inc);
            ans += c;
        }
        return ans;

    }
}