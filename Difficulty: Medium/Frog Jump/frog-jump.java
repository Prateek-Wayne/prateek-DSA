// User function Template for Java
class Solution {
    int helper(int[] height, int ind, int[] dp) {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int left = helper(height, ind - 1, dp) + Math.abs(height[ind] - height[ind - 1]);
        int right = Integer.MAX_VALUE;
        if (ind > 1)
            right = helper(height, ind - 2, dp) + Math.abs(height[ind] - height[ind - 2]);
        return dp[ind] = Math.min(left, right);

    }

    int minCost(int[] height) {
        // code here
        int n = height.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return helper(height, n-1, dp);

    }
}