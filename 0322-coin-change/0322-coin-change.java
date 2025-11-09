class Solution {
    int helper(int[] coins, int amount, int index, Integer[][] dp) {
        if (index == 0) {
            if (amount % coins[index] == 0)
                return amount / coins[index];
            return (int) 1e9;
        }
        if (dp[index][amount] != null)
            return dp[index][amount];

        // not pick
        int notPick = helper(coins, amount, index - 1, dp);
        // pick
        int pick = Integer.MAX_VALUE;
        if (coins[index] <= amount)
            pick = 1 + helper(coins, amount - coins[index], index, dp);
        return dp[index][amount] = Math.min(notPick, pick);
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        Integer[][] dp = new Integer[n][amount + 1];
        int ans = helper(coins, amount, n - 1, dp);
        return ans >= 1e9 ? -1 : ans;
    }
}