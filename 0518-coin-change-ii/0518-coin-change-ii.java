class Solution {
       int helper(int amount, int[] coins, int index, Integer[][] dp) {
        if (index == 0) {
            if (amount % coins[index] == 0)
                return 1;
            return 0;
        }
        if (dp[index][amount] != null)
            return dp[index][amount];
        int pick = 0;
        if (coins[index] <= amount)
            pick = helper(amount - coins[index], coins, index, dp);
        int notPick = helper(amount, coins, index - 1, dp);
        return dp[index][amount] = pick + notPick;
    }

    public int change(int amount, int[] coins) {
        int n = coins.length;
        Integer[][] dp = new Integer[n][amount + 1];
        return helper(amount, coins, n - 1, dp);

    }
}