class Solution {
int helper(String word1, String word2, int index1, int index2, int[][] dp) {

        if (index1 < 0) {
            return index2 + 1;
        }
        if (index2 < 0) {
            return index1 + 1;
        }
        if (word1.charAt(index1) == word2.charAt(index2)) {
            return 0 + helper(word1, word2, index1 - 1, index2 - 1, dp);
        }
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        // delete
        int delete = 1 + helper(word1, word2, index1 - 1, index2, dp);
        // replace
        int replace = 1 + helper(word1, word2, index1 - 1, index2 - 1, dp);
        // insert
        int insert = 1 + helper(word1, word2, index1, index2 - 1, dp);
        return dp[index1][index2] = Math.min(delete, Math.min(insert, replace));
    }

    public int minDistance(String word1, String word2) {
        int index1 = word1.length();
        int index2 = word2.length();
        int[][] dp = new int[index1 + 1][index2 + 1];
        for (int i = 0; i <= index1; i++) {
            int[] temp = new int[index2 + 1];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        return helper(word1, word2, index1 - 1, index2 - 1, dp);
    }
}