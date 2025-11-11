class Solution {
 int checkZeroes(String s) {
        int countZero = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0')
                countZero++;
        }
        return countZero;
    }

    int checkOnes(String s) {
        int countOnes = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1')
                countOnes++;
        }
        return countOnes;
    }

       int helper(String[] strs, int m, int n, int index, List<String> ds, Integer[][][] dp) {
        if (index < 0)
            return 0;
        if (dp[index][m][n] != null)
            return dp[index][m][n];
        // not pick
        int notPick = helper(strs, m, n, index - 1, ds, dp);
        int pick = 0;
        int zeroes = checkZeroes(strs[index]);
        int ones = checkOnes(strs[index]);
        if (m - zeroes >= 0 && n - ones >= 0) {
            ds.add(strs[index]);
            pick = 1 + helper(strs, m - zeroes, n - ones, index - 1, ds, dp);
            ds.removeLast();
        }
        return dp[index][m][n] = Math.max(notPick, pick);

    }

    public int findMaxForm(String[] strs, int m, int n) {
        List<String> ds = new ArrayList<>();
        int index = strs.length;
        Integer[][][] dp = new Integer[index][m + 1][n + 1];
        return helper(strs, m, n, index - 1, ds, dp);
    }
}