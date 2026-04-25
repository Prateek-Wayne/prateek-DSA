class Solution {

    int helper(int[] cost, int i, int[] dp) {
        if (i >= cost.length) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        int left = cost[i] + helper(cost, i + 1, dp);
        int right = cost[i] + helper(cost, i + 2, dp);
        return dp[i] =Math.min(left, right);
    }

    public int minCostClimbingStairs(int[] cost) {
        int n=cost.length;
        int[] dp=new int[n];
        Arrays.fill(dp,-1);
        return Math.min(helper(cost,0,dp) , helper(cost,1,dp));
    }
}