class Solution {
 public int helper(int[] coins, int amount, int index, int[][] dp) {
        if (amount < 0 || index < 0)
            return 0;
        if (amount == 0) {
            return 1;
        }
        // pick...
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int pick = 0;
        if (coins[index] <= amount) {
            pick += helper(coins, amount - coins[index], index, dp);
        }
        int notPick = helper(coins, amount, index - 1, dp);
        return dp[index][amount] = pick + notPick;
    }

    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[n + 1][amount + 1];
        for (int[] arr : dp) {
            Arrays.fill(arr, -1);
        }
        return helper(coins, amount, n - 1, dp);
    }
}