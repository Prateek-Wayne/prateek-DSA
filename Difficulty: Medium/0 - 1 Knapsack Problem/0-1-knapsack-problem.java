class Solution {
    int helper(int W, int val[], int wt[], int ind, Integer[][] dp) {
        if (ind == 0) {
            if (wt[ind] <= W)
                return val[ind];
            return 0;
        }
        if (dp[ind][W] != null)
            return dp[ind][W];
        // pick...
        int pick = Integer.MIN_VALUE;
        if (wt[ind] <= W)
            pick = val[ind] + helper(W - wt[ind], val, wt, ind - 1, dp);
        int notPick = 0 + helper(W, val, wt, ind - 1, dp);
        return dp[ind][W] = Math.max(pick, notPick);
    }

    public int knapsack(int W, int val[], int wt[]) {
        int n = wt.length;
        Integer[][] dp = new Integer[n][W + 1];
        return helper(W, val, wt, n - 1, dp);
    }
}
