class Solution {

    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        long[] diff = new long[n];
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = i;
            int inc = shifts[i];
            diff[start] += inc;
            if (end + 1 < n)
                diff[end + 1] -= inc;
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < n; i++) {

            long shift = ((diff[i] % 26) + 26) % 26;

            int idx = (int)(s.charAt(i) - 'a' + shift) % 26;

            ans.append((char) ('a' + idx));
        }

        return ans.toString();

    }
}