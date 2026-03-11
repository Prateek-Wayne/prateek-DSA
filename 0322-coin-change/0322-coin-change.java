class Solution {
int helper(int[] coins, int amount, int index, int[][] dp) {

    if (index == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return Integer.MAX_VALUE;
    }

    if (dp[amount][index] != -1)
        return dp[amount][index];

    int notPick = helper(coins, amount, index - 1, dp);

    int pick = Integer.MAX_VALUE;

    if (amount >= coins[index]) {

        int res = helper(coins, amount - coins[index], index, dp);

        if (res != Integer.MAX_VALUE)
            pick = 1 + res;
    }

    return dp[amount][index] = Math.min(pick, notPick);
}

public int coinChange(int[] coins, int amount) {

    int n = coins.length;

    int[][] dp = new int[amount + 1][n];

    for (int i = 0; i <= amount; i++)
        Arrays.fill(dp[i], -1);

    int ans = helper(coins, amount, n - 1, dp);

    return ans == Integer.MAX_VALUE ? -1 : ans;
}
}