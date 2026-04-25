class Solution {
    int helper(int i, int[] cost, int[] dp) {
        if (i <= 1)
            return 0; // base: start from 0 or 1

        if (dp[i] != -1)
            return dp[i];

        int oneStep = helper(i - 1, cost, dp) + cost[i - 1];
        int twoStep = helper(i - 2, cost, dp) + cost[i - 2];

        return dp[i] = Math.min(oneStep, twoStep);
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);

        return helper(n, cost, dp);
    }
}