class Solution {
    Boolean solve(String s, int i, int j) {
        if (i >= j)
            return true;
        if (s.charAt(i) == s.charAt(j)) {
            return solve(s, i+1, j-1);
        }
        return false;
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(s, i, j)) {
                    if (maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        ans.delete(0, ans.length());
                        ans = new StringBuilder(s.subSequence(i, j + 1));
                    }
                }
            }
        }
        return ans.toString();
    }
}